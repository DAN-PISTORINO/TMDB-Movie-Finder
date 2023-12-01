// Replace with your TMDB API key
const API_KEY = "1857e2cb374e86db84f27a8550dc6e24";


const txtSearchMovie = document.getElementById("txtSearchMovie");
const searchButton = document.getElementById("searchButton");
const resultsContainer = document.getElementById("resultsContainer");

txtSearchMovie.addEventListener("keyup", updateMovieSearch);

// c++ binding to update the input box
function updateMovieSearch(txt) {
    txtSearchMovie.value += txt;
};

function bindTxtMovieSearch() {
    var strMovie = document.querySelector('#txtSearchMovie');
    strMovie.onkeypress = (function (e) {

        /* // do good things
        if (e.which == '13') {
            strMovie.blur();
            let url = strMovie.value;
            if (anchorme.validate.url(url) || anchorme.validate.ip(url)) {
                if (url.toLowerCase().startsWith("http://") || url.toLowerCase().startsWith("https://")) {
                    OnRequestChangeURL(url);
                } else {
                    OnRequestChangeURL("http://" + url);
                }
            } else if (url.toLowerCase().startsWith("file:///")) {
                OnRequestChangeURL(url);
            } else if (url.toLowerCase().startsWith("file://")) {
                OnRequestChangeURL("file:///" + url.substring(7));
            } else {
                // Interpret as search
                OnRequestChangeURL("https://www.google.com/search?q=" + encodeURIComponent(url));
            }

            return false;
        }
        */
    });
};

async function searchMovies() {
    const movieTitle = txtSearchMovie.value.trim();

    if (!movieTitle) {
        return;
    }

    const url = `https://api.themoviedb.org/3/search/movie?api_key=${API_KEY}&query=${movieTitle}`;
    const response = await fetch(url);
    const data = await response.json();

    if (!data.results.length) {
        resultsContainer.innerHTML = "No results found";
        return;
    }
    
    const movies = data.results;
    const movieData = movies.map((movie) => {
        return {
            id: movie.id,
            title: movie.title,
            overview: movie.overview,
            poster_path: movie.poster_path,
        };
    });

    // Save movie data to JSON file
    const fileName = "movieSearchResults.json";
    const fileContent = JSON.stringify(movieData, null, 2);
    await saveAs(fileContent, fileName, { type: "json" });

    // Display search results
    const resultsHTML = movies.map((movie) => {
        return `<div class="movie-result">
      <img src="https://image.tmdb.org/t/p/w185/${movie.poster_path}" alt="${movie.title}">
      <h3>${movie.title}</h3>
      <p>${movie.overview}</p>
    </div>`;
    }).join("");

    resultsContainer.innerHTML = resultsHTML;

    // notify c++ of search results so it can make changes to the other json files: search history, stats
    //var selectedClass = btnDashboard();
};

