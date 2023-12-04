#include <iostream>
#include <fstream>
#include "SplayTree.hpp"
#include "json.hpp"
#include <chrono>
#include <utility>

using namespace std;
using namespace std::chrono;
using json = nlohmann::json;

string movies_to_str(vector<Node*>& movies) {
    string result = "{\n";

    result += "\"movies\": [\n";
    for(int i = 0; i < movies.size() - 1; i++) {
        result += "{\n";
        result += R"("movieID": ")" + movies[i]->movieID + "\",\n";
        result += R"("title": ")" + movies[i]->movie + "\"";
        result += "\n},\n";
    }

    result += "{";
    result += R"("movieID": ")" + movies[movies.size() - 1]->movieID + "\",\n";
    result += R"("title": ")" + movies[movies.size() - 1]->movie + "\"";
    result += "}\n";
    result += "}\n],\n";

    return result;
}

string duration_str(string movies, long long int time) {
    string final = std::move(movies);
    final += "\"duration\": [\n";
    final += "{\n";
    final += R"("time": ")" + std::to_string(time) + "\"\n";
    final += "}\n";
    final += "]\n";
    final += "}";
    return final;

}

int main() {
    auto start = std::chrono::steady_clock::now();

    std::ifstream f("../movie_data.json");
    SplayTree movie_tree;

    string line;
    json movie_data = json::parse(f);
    for(auto & i : movie_data) {
        string mv_title = i["primaryTitle"];
        string mv_id = i["tconst"];

        string year;
        year = i["startYear"];
        int mv_year = 0;
        if (year == (R"(\\N)") || year == (R"(\N)")) {
            mv_year = -1;
        } else {
            mv_year = stoi(year);
        }

        string mv_genres = i["genres"];
        string mv_category;
        if (mv_genres == (R"(\\N)") || mv_genres == (R"(\N)")) {
            mv_category = "";
        }
        else if(mv_genres.find(',') != string::npos) {
            mv_category = mv_genres.substr(0, mv_genres.find(','));
        }
        else {
            mv_category = mv_genres;
        }

        //SplayTree::insert(int &year, string &movie, string &category, string &movieID)
        movie_tree.insert(mv_year, mv_title, mv_category, mv_id);
    }

    cout << "Search for genre: " << endl;
    string user_genre;
    cin >> user_genre;

    vector<Node*> result_movies;
    movie_tree.search(result_movies, user_genre);

    string final1 = movies_to_str(result_movies);

    auto stop = std::chrono::steady_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;


    string final2 = duration_str(final1, duration.count());
    cout << final2;
    return 0;
}
