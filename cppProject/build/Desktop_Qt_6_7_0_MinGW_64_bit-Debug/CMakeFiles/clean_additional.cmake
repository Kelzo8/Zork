# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\cppProject_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\cppProject_autogen.dir\\ParseCache.txt"
  "cppProject_autogen"
  )
endif()
