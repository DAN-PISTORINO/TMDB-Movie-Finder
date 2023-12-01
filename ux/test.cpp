#define CATCH_CONFIG_MAIN
#ifdef CATCH_CONFIG_MAIN

#define TESTING
#include "catch2/catch_test_macros.hpp"
#include <iostream>

#include "MyApp.h"
#include "MovieLib.h"
#include <filesystem>
#include <fstream>

using namespace std;

// things to test:
// RB Tree
// SPLAY TREE
// MovieLib
// R/W json
// MyApp

TEST_CASE("MovieLib", "[html]") {
    //MyApp app = MyApp();
    //app.Run();
    const string testString = "{this {is {a}} test}";
    MovieLib ml = MovieLib("1857e2cb374e86db84f27a8550dc6e24");
    auto ss = std::stringstream(testString);
    ml.writeJsonFile("test/writeJsonFile/writeJsonFile.json", &ss);
    auto fpath = path("test/writeJsonFile/writeJsonFile.json");
    auto ifs = fstream(fpath,fstream::openmode(1));
   
    REQUIRE(exists(fpath));
}
#undef TESTING
#endif //CATCH_CONFIG_MAIN