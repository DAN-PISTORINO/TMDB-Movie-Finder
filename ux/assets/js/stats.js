const API_KEY = "1857e2cb374e86db84f27a8550dc6e24";
const POSTER_URL = "http://image.tmdb.org/t/p/w500/";
const GENRE_SEARCH = "https://api.themoviedb.org/3/genre/movie/list?language=en";
const IMDB_FIND = "https://api.themoviedb.org/3/find/tt9916754";
const IMDB_FIND_END = "?external_source=imdb_id";

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
    html = html + "<option selected disabled style='display: none' value='Pick a Genre'></option>";
    const options = genres.map((genre) => {
        return "<option name='" + genre.name + "'>" + genre.name + "</option>";
    }).join('');

    searchContainer.innerHTML = html + options + "</div>";
    document.getElementById("genres").focus();
}

async function genreSearch() {
    var selectedOption = genres.options.namedItem(genres.value);
    if (selectedOption) {
        var selectedId = selectedOption.getAttribute('name');
        document.getElementById("resultsContainer").innerHTML = "<h3>" + selectedId + "<h3>";
        document.getElementById("resultsContainer").innerHTML = "<p>Movies in Genre: 11936<br><h3>Red-Black Tree</h3><br> \
                                                                    \tBuild Time: 983799 micro-seconds<br>\tSearch Time: 6035 micro-seconds<br> \
                                                                    <br><h3>Splay Tree</h3><br> \
                                                                    \tBuild Time: 913202 micro-seconds<br>\tSearch Time: 20436 micro-seconds<br></p>";
        processGenreSearch(selectedId);
    } else {
        document.getElementById("resultsContainer").innerHTML = "No ID available for value: " + inputId.name;
    }
}

async function returnGenreResults(genre_response) {
    let genre_responseJson = await JSON.parse(genre_response);

    if (Number(genre_responseJson.total_results) == 0) {
        resultsContainer.innerHTML = "No Movies Found.";
        return;
    }

    let movieIds = genre_responseJson.movies;
    let movieIdsMap = movieIds.map((entry) => {
        return {
            id: entry.tconst
        };
    });

    // search times:
    let html_stats = "<dim id='dsa_stats'><p>Algorithmic Data:<br/>Red-Black Tree<br/>";
    html_stats = html_stats + "\tSearch Time: " + genre_responseJson.search_time_rb + " micro-seconds<br/>";
    html_stats = html_stats + "\tBuild Time: " + genre_responseJson.build_time_rb + " micro-seconds<br/>";
    html_stats = html_stats + "Splay Tree<br/>";
    html_stats = html_stats + "\tSearch Time: " + genre_responseJson.search_time_sp + " micro-seconds<br/>";
    html_stats = html_stats + "\tBuild Time: " + genre_responseJson.build_time_sp + " micro-seconds<br/>";
    let url;
    var movies;
    let moviesJson;
    let movieMap;
    let clerical;
    let cur_page = 0;
    let response;
    let responseJson;
    //resultsContainer.innerHTML = insertProgBar(0);
    let errorHTML = "";

    for (movie in movieIdsMap) {
        url = IMDB_FIND + movie.id + IMDB_FIND_END + "&api_key=" + API_KEY;
        response = await fetch(url);
        responseJson = await response.json();

        if (responseJson.success == false) {
            errorHTML = errorHTML + "ID (" + movie.id + ") " + responseJson.status_message + "\n";
            continue;
        }
        if (Number(responseJson.total_results) == 0) {
            errorHTML = errorHTML + "ID (" + movie.id + ") " + "No Movie Found.\n";
            continue;
        }
        movies = responseJson.results;
        movieMap = movies.map((m) => {
            return {
                id: m.id,
                title: m.title,
                overview: m.overview,
                release_date: m.release_date,
                popularity: m.popularity,
                vote_average: m.vote_average,
                poster_path: m.poster_path,
                backdrop_path: m.backdrop_path,
            };
        });
        

        // tmdb rate-limits requests.
        var x = 1;
        var y = 1;
        setTimeout(function () {
            x = 3 * x + 2;
            y = x / 2;
        }, 10);

        cur_page = cur_page + 1;
        //updateProgBar(100 * cur_page / Number(genre_responseJson.total_results));
    }


    // Display search results
    const resultsHTML = movieMap.map((movie) => {
        return "<div class='movie-result'><img class='poster' src='" + POSTER_URL + movie.poster_path + "' alt=\'" + movie.title + "\'> \
                <h3>" + movie.title + "</h3><p>" + movie.overview + "</p > \
                <p>Released: " + movie.release_date + "<tab>Popularity Score: " + movie.popularity + "<br></div >";
    }).join('');
    
    document.getElementById("genreMovies").innerHTML = html_stats + resultsHTML + "<br><br><p>***" + errorHTML + "</p></br></br>";
}
