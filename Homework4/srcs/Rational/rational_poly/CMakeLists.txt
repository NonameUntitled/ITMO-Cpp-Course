cmake_minimum_required(VERSION 3.10.2)

include_directories(../lib_rational)

project(rational_poly)

add_library(rational_poly rational_poly.cpp)

target_link_libraries(rational_poly lib_rational)

get_property(
        LIB_TYPE
        TARGET rational_poly
        PROPERTY TYPE)

if (LIB_TYPE STREQUAL SHARED_LIBRARY)
    install(
            TARGETS rational_poly
            COMPONENT user
            RUNTIME
            DESTINATION bin
            LIBRARY
            DESTINATION lib)
endif ()

install(
        TARGETS rational_poly
        EXPORT rational_poly
        COMPONENT developer
        RUNTIME
        DESTINATION bin
        LIBRARY
        DESTINATION lib
        ARCHIVE
        DESTINATION lib)

install(
        DIRECTORY .
        DESTINATION include
        COMPONENT developer
        FILES_MATCHING
        PATTERN "*.h")

install(
        EXPORT rational_poly
        DESTINATION share
        COMPONENT developer)
