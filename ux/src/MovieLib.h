#pragma once

// multiplex download
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <nlohmann/json.hpp>
#include <ctime>
#include <fstream>
#include <filesystem>

#define fs std::filesystem

using json = nlohmann::json;
using std::string;

#define create_directory fs::create_directory;
using namespace std::filesystem;

/* CREDITS - since Rome was not built by any one person.
	The following was designed by Daniel Stenberg, <daniel@haxx.se> as sample for available on https://curl.se
	Structs:
		transfer, MemoryStruct
	Methods:
		WriteMemoryCallback() - for storing downloads into memory
		dump(), my_trace(), and setup() - multiple downloads for single call

*/

class MovieLib {
public:
	// we will include our structures here

	json* movieIds;
	bool readDataJson(path* filepath, json* jdata);
	bool writeDataJson(path* filepath, json* jdata);

	string db_key;
	
	bool writeJsonDataStringstream(path* filepath, std::stringstream* data);
	//bool readJsonDataStringstream(path* filepath, std::stringstream* data);

public:
	MovieLib(path* movieId_filepath);
	~MovieLib();
};