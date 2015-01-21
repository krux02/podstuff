all: example

example: main.cpp podstuff.h
	g++ -std=c++11 main.cpp -o example
