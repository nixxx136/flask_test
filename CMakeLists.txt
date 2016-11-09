cmake_minimum_required (VERSION 2.8)
PROJECT (add)

# ###############################
# Boost
#
SET(Boost_USE_STATIC_LIBS ON)
FIND_PACKAGE(Boost REQUIRED)
FIND_PACKAGE(Boost COMPONENTS program_options REQUIRED)
IF(${Boost_FOUND})
  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
ELSE()
  MESSAGE(FATAL ERROR "Boost could not be located and is required for libsivelab.")
ENDIF()

include_directories(${CMAKE_SOURCE_DIR})

add_executable(add
    add.cpp
    json/json.h json/jsoncpp.cpp
    ArgumentParsing.h ArgumentParsing.cpp)

target_link_libraries(add ${Boost_PROGRAM_OPTIONS_LIBRARIES})
target_compile_features(add PRIVATE cxx_range_for)
