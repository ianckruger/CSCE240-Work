flags = -Wall -std=c_++17

isPrime.o : isPrime.cc isPrime.h
	g++ $(flags) -c $<

functions.o : functions.cc isPrime.h
	g++ $(flags) -c functions.cc

functions : functions.o isPrime.h
	g++ $(flags) $^ -o functions
	./functions

clean :
	rm *.o functions