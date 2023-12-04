const API_KEY = "1857e2cb374e86db84f27a8550dc6e24";
const POSTER_URL = "http://image.tmdb.org/t/p/w500/";
const GENRE_SEARCH = "https://api.themoviedb.org/3/genre/movie/list?language=en"

async function getGenres() {
    const url = GENRE_SEARCH + "&api_key=" + API_KEY;
    const searchContainer = document.getElementById("searchContainer");
    const resultsContainer = document.getElementById("resultsContainer");

    let response = await fetch(url);
    let responseJson = await response.json();

    if (responseJson.success == false) {
        resultsContainer.innerHTML = responseJson.status_message;
        return;
    }
    if (Number(responseJson.total_results) == 0) {
        resultsContainer.innerHTML = "Genres failed to load.";
        return;
    }
    let genres = responseJson.genres;
    // Display genres results
    let html = "<div class='genre-list'><select id='genres' title='Genres' onchange='if (this.selectedIndex) genreSearch();' >";
    html = html + "<option selected disabled style='display: none' value=''></option>";
    const options = genres.map((genre) => {
        return "<option name='" + genre.name + "'>" + genre.name + "</option>";
    }).join('');
    searchContainer.innerHTML = html + options + "</div>"; //"</select><button id='genreSubmit' type='submit' onclick='genreSearch();'>Submit</button></div>";
    document.getElementById("genres").focus();
}

async function genreSearch() {
    var selectedOption = genres.options.namedItem(genres.value);
    if (selectedOption) {
        var selectedId = selectedOption.getAttribute('name');
        document.getElementById("resultsContainer").innerHTML = "<h3>" + selectedId + "<h3>";
        processGenreSearch(selectedId);
    } else {
        document.getElementById("resultsContainer").innerHTML = "No ID available for value: " + inputId.name;
    }
}

async function returnGenreResults(jsonString) {
    let response = jsonString;
    let responseJson = await JSON.parse(response);

    if (Number(responseJson.total_results) == 0) {
        resultsContainer.innerHTML = "No Movies Found.";
        return;
    }
    let movies = responseJson;
    let movieMap = movies.map((movie) => {
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

    // Display search results
    const resultsHTML = movieMap.map((movie) => {
        return "<div class='movie-results'><img class='poster' src='" + POSTER_URL + movie.poster_path + "' alt=''" + movie.title + "''> \
                <h3>" + movie.title + "</h3><p>" + movie.overview + "</p > \
                <p>Released: " + movie.release_date + "<tab>Popularity Score: " + movie.popularity + "<br></div >";
    }).join('');

    document.getElementById("resultsContainer").innerHTML = resultsHTML;
}

//async function processGenreSearch() {
//    return '[{"id": 116776, "title": "Dragon Ball: Mystical Adventure", "overview": "Master Roshi has succeeded at the one mission he valued most: to train Goku and Krillin to become ultimate fighters. So, he arranges for them to test their mettle at a competition hosted by Emperor Chiaotzu. Not everyone\'s playing by the rules, however, as a member of the ruler\'s household schemes to use the Dragonballs to extort money and power from the royal.", "release_date": "1988-07-09", "popularity": 340.423, "vote_average": 6.756, "poster_path": "/5aXG0B3TYTpQsodXzvYCkKQfpB1.jpg", "backdrop_path": null}]';
//}