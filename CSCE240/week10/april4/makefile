#	$@ target
# $< first prerequisite
# $^ all prerequisites

flags = -std=c++17 -Wall -I .

Employee.o : Employee.cc Employee.h
	g++ $(flags) -c $<

HourlyEmployee.o : HourlyEmployee.cc HourlyEmployee.h Employee.h
	g++ $(flags) -c $<

SalariedEmployee.o : SalariedEmployee.cc SalariedEmployee.h Employee.h
	g++ $(flags) -c $<

test.o : test.cc HourlyEmployee.h Employee.h
	g++ $(flags) -c $<

test : test.o Employee.o HourlyEmployee.o SalariedEmployee.o
	g++ $(flags) $^
	./a.out

clean :
	rm *.o a.out
