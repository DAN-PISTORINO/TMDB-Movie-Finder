const API_KEY = "1857e2cb374e86db84f27a8550dc6e24";
const POSTER_URL = "http://image.tmdb.org/t/p/w500/";
const COMPANY_LOGO_URL = "https://image.tmdb.org/t/p/w154/";
const MOVIE_SEARCH = "https://api.themoviedb.org/3/search/movie?query="
//function sendFileToCpp(filename, movieTitle, searchTerm) { return GetStringFromJS(filename, movieTitle, searchTerm); }

function insertProgBar(prog) {
    return 'Loading Records...<div class="progress-bar"><div class="progress-bar-filled" style="width: '+prog+'%;" ></div ></div >';
}

// Function to update the progress bar
async function updateProgBar(percentage) {
    const progressBar = document.querySelector('.progress-bar-filled');
    progressBar.style.width = `${percentage}%`;
}

async function searchMovies() {
    const searchTerm = txtSearchMovie.value.trim();
    resultsContainer = document.getElementById("resultsContainer");
    if (!searchTerm) {
        return;
    }

    const url = MOVIE_SEARCH + searchTerm + "&api_key=" + API_KEY + "&language=en-US&page=";
    var movies;
    let moviesJson;
    let movieMap;
    let clerical;
    let cur_page = 0;
    let response;
    let responseJson;
    resultsContainer.innerHTML = insertProgBar(0);

    do {
        cur_page = cur_page + 1;
        response = await fetch(url + cur_page);
        responseJson = await response.json();

        if (responseJson.success == false) {
            resultsContainer.innerHTML = responseJson.status_message;
            return;
        }
        if (Number(responseJson.total_results) == 0) {
            resultsContainer.innerHTML = "No Movies Found.";
            return;
        }
        movies = responseJson.results;
        movieMap = movies.map((movie) => {
            return {
                id: movie.id,
                title: movie.title,
                overview: movie.overview,
                release_date: movie.release_date,
                popularity: movie.popularity,
                vote_average: movie.vote_average,
                poster_path: movie.poster_path,
                backdrop_path: movie.backdrop_path,
            };
        });

        if (cur_page == 1) { moviesJson = movieMap; }
        else {
            moviesJson = moviesJson.concat(movieMap);
        }         

        updateProgBar(100 * Number(responseJson.page) / Number(responseJson.total_pages));
        // tmdb rate-limits requests.
        var x = 1;
        var y = 1;
        setTimeout(function () {
            x = 3 * x + 2;
            y = x / 2;
        }, 10);

    } while (Number(responseJson.page, 10) < Number(responseJson.total_pages, 10))

    
    // Display search results
    const resultsHTML = moviesJson.map((movie) => {
        return "<div class='movie-result'><img class='poster' src='" + POSTER_URL + movie.poster_path + "' alt=''" + movie.title + "''> \
                <h3>" + movie.title + "</h3><p>" + movie.overview + "</p > \
                <p>Released: " + movie.release_date + "<tab>Popularity Score: " + movie.popularity + "<br></div >";
    }).join('');

    resultsContainer.innerHTML = resultsHTML;
    
    // Save movie data to JSON file
    const fileName = "movieSearchResults.json";
    const fileContent = JSON.stringify(moviesJson, null, 2);
    
    sendFileToCpp(fileName, fileContent, searchTerm);    
};

