main: main.o Sorting.o
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -o main Main.o
main.o: Main.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c Main.cpp
Sorting.o: Sorting.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c Sorting.cpp
clean:
	rm main Main.o