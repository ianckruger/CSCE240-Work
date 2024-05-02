driver.o : driver.cc LengthUnit.h
	g++ -c -Wall -std=c++17 $<

LengthUnit.o : LengthUnit.cc LengthUnit.h
	g++ -c -Wall -std=c++17 $<

Length.o : Length.cc Length.h LengthUnit.h
	g++ -c -Wall -std=c++17 $<

test : driver.o LengthUnit.o Length.o
	g++ -Wall -std=c++17 $^
	./a.out

clean :
	rm *.o a.out
