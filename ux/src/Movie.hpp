#pragma once
#include <string>

using std::string;

class Movie {
private:
    void getInfo();
public:
    Movie(int year, string movie, string actor, string category);
    Movie() = default;
    int year;
    string movie;
    string actor;
    string category;
    string base_url;
    string file_size;
    string file_path;
};

Movie::Movie(int year, string movie, string actor, string category): year(year), movie(movie), actor(actor), category(category) {

}

void Movie::getInfo() {

}