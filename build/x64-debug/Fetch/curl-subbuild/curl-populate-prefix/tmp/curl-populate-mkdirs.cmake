# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/temp/OLD/ult3/build/x64-debug/ux/../Fetch/curl-src"
  "D:/temp/OLD/ult3/build/x64-debug/ux/../Fetch/curl-build"
  "D:/temp/OLD/ult3/build/x64-debug/Fetch/curl-subbuild/curl-populate-prefix"
  "D:/temp/OLD/ult3/build/x64-debug/Fetch/curl-subbuild/curl-populate-prefix/tmp"
  "D:/temp/OLD/ult3/build/x64-debug/Fetch/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp"
  "D:/temp/OLD/ult3/build/x64-debug/Fetch/curl-subbuild/curl-populate-prefix/src"
  "D:/temp/OLD/ult3/build/x64-debug/Fetch/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/temp/OLD/ult3/build/x64-debug/Fetch/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/temp/OLD/ult3/build/x64-debug/Fetch/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
