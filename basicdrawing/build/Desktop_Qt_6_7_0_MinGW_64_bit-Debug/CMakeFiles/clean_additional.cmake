# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\basicdrawing_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\basicdrawing_autogen.dir\\ParseCache.txt"
  "basicdrawing_autogen"
  )
endif()
