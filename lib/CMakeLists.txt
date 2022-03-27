project(pp_lib LANGUAGES C)
cmake_minimum_required(VERSION 3.22)

add_library(pp_compose_arg lib/compose/arg.h lib/compose/arg.c)
add_library(pp_parse_arg lib/parse/arg.h lib/parse/arg.c)
