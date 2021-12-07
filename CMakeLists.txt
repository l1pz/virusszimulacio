cmake_minimum_required(VERSION 3.16)
project(virusszimulacio C)

set(CMAKE_C_STANDARD 99)

add_executable(virusszimulacio main.c Ember.c Ember.h Seged.h Szimulacio.c Szimulacio.h Seged.c)
