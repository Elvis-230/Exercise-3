CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Targets
all: main test

main: main.o Student.o
	$(CXX) $(CXXFLAGS) -o main main.o Student.o

test: test.o Student.o
	$(CXX) $(CXXFLAGS) -o test test.o Student.o

main.o: main.cpp Student.h
	$(CXX) $(CXXFLAGS) -c main.cpp

test.o: test.cpp Student.h
	$(CXX) $(CXXFLAGS) -c test.cpp

Student.o: Student.cpp Student.h
	$(CXX) $(CXXFLAGS) -c Student.cpp

clean:
	rm -f *.o main test

run-main: main
	./main

run-test: test
	./test

.PHONY: all clean run-main run-test
