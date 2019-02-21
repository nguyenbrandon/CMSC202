Cxx = g++
CXXFLAGS = -Wall

proj3: LinkedList.o proj3.cpp
	$(CXX) $(CXXFLAGS) LinkedList.o proj3.cpp -o proj3

LinkedList.o: LinkedList.cpp LinkedList.h
	$(CXX) $(CXXFLAGS) -c LinkedList.cpp

clean: rm *.o
	rm *~

run:
	./proj3