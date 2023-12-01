// Replace with your TMDB API key
const API_KEY = "1857e2cb374e86db84f27a8550dc6e24";

//txtSearchMovie.addEventListener("requestMovieSearchUpdate", updateMovieSearch(this.value));

// c++ binding to update the input box
async function updateMovieSearch(txt) {
    txtSearchMovie = document.getElementById("txtSearchMovie");
    //txtSearchMovie.value = txt;
    
};
var search_results = "";

async function sendFileToCpp(filename, str) { return getFileFromJS(filename, str); }

function bindTxtMovieSearch() {
    var strMovie = document.querySelector('#txtSearchMovie');
    strMovie.onkeypress = (function (e) {
        // to keypress stuff here.
        var d = "";
    });
};

async function writeJson(fileName, fileContent) {
    const FileSystem = require('fs');
    fs.writeFile(fileName, fileContent, (err) => { if (err) throw err; });
    // should notify c++ once file is written;
};

async function searchMovies() {
    const movieTitle = txtSearchMovie.value.trim();
    resultsContainer = document.getElementById("resultsContainer");
    if (!movieTitle) {
        return;
    }

    const url = "https://api.themoviedb.org/3/search/movie?query=" + movieTitle + "&api_key=" + API_KEY;
    const response = await fetch(url);
    const data = await response.json();

    if (data.success==false) {
        resultsContainer.innerHTML = data.status_message;
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

    //const FileSystem = require("fs");
    sendFileToCpp(fileName, fileContent);
    
    // Display search results
    const resultsHTML = movies.map((movie) => {
        return `<div class="movie-result">
      <img src="https://image.tmdb.org/t/p/w185/${movie.poster_path}" alt="${movie.title}">
      <h3>${movie.title}</h3>
      <p>${movie.overview}</p>
    </div>`;
    }).join("");

    resultsContainer.document.innerHTML = resultsHTML;

    // notify c++ of search results so it can make changes to the other json files: search history, stats
    //var selectedClass = btnDashboard();
};

