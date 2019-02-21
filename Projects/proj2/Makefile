CXX = g++
CXXFLAGS = -Wall

test: Pokemon.o MyPokemon.o proj2.cpp
	$(CXX) $(CXXFLAGS) -ansi Pokemon.o MyPokemon.o proj2.cpp -o test

Pokemon.o: Pokemon.cpp Pokemon.h
	$(CXX) $(CXXFLAGS) -ansi Pokemon.cpp

MyPokemon.o: MyPokemon.cpp MyPokemon.h
	$(CXX) $(CXXFLAGS) -ansi MyPokemon.cpp

clean:
	rm *.o
	rm *~

run:
	./test