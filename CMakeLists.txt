cmake_minimum_required(VERSION 3.30)
project(FinalProjectYuvalAndYuval C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(FinalProjectYuvalAndYuval
    Athlete.c
    Athlete.h
    City.c
    City.h
    Country.c
    Country.h
    Date.c
    Date.h
    General.c
    General.h
    List.c
    List.h
    Main.c
    Match.c
    Match.h
    Olympics.c
    Olympics.h
    Sport.c
    Sport.h
    Venue.c
    Venue.h)
