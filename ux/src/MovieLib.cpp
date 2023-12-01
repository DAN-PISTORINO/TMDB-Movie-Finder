#include "MovieLib.h"

#define NUM_HANDLES 1000
#define TMDB_VALID_KEY_CODE 200;
#define TMDB_INVALID_KEY_CODE 401;

#define create_directory fs::create_directory;

MovieLib::MovieLib(path* movieId_filepath) {
    // TMDB load movie data from json
    
    // need to write this to file and read in data from file.
}

MovieLib::~MovieLib() {
}

// writes string data to a filepath and returns success or failure
bool MovieLib::writeJsonDataStringstream(path* jsonFile, std::stringstream* data) {
    // check if path director exists;
    if (true) {//!exists(jsonFile)) {
        //if (!exists(jsonFile->relative_path()))
            //fs::create_directories(jsonFil);
        json json_data;
        (*data) >> json_data;
        //std::ofstream of = std::ofstream(jsonFile);
        if (jsonFile) {
        //    jsonFile.write(to_string(json_data).c_str(), to_string(json_data).size());
            return true;
        }
        else
            return false;
    }
    //else
    //    return true;    // file already exists
}

// reads a json object from file and returns success/failure
bool MovieLib::readDataJson(path* filepath, json* jdata) {
    
    return false;
}

// writes a json object from file and returns success/failure
bool MovieLib::writeDataJson(path* filepath, json* jdata) {

    return false;
}
