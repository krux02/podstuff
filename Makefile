all: example

example: main.cpp cpphelpers.h
	g++ -std=c++11 main.cpp -o example
