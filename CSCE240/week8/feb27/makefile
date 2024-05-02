driver.o : driver.cc LengthUnit.h
	g++ -c -Wall -std=c++17 $<

LengthUnit.o : LengthUnit.cc LengthUnit.h
	g++ -c -Wall -std=c++17 $<

test : driver.o LengthUnit.o
	g++ -Wall -std=c++17 $^
	./a.out

clean :
	rm *.o a.out
