# Makefile for Space Shooter game

all: shooter

shooter: main.o
	clang++ -o shooter main.o -std=c++17 -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

main.o: space_shooter.cpp input.hpp loader.hpp
	clang++ -o main.o space_shooter.cpp -std=c++17 -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
