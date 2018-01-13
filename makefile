
CXXFLAGS = -Wall -c $(DEBUG) -std=c++11 -pthread

output: p4main.o gameplay.o character.o 0vampire.o 1barbarian.o 2bluemen.o 3medusa.o 4harrypotter.o tournament.o lineup.o loserBracket.o
	g++ p4main.o gameplay.o character.o 0vampire.o 1barbarian.o 2bluemen.o 3medusa.o 4harrypotter.o tournament.o lineup.o loserBracket.o -o p4

p4main.o: p4main.cpp
	g++ -c p4main.cpp

gameplay.o: gameplay.cpp
	g++ -c gameplay.cpp

character.o: character.cpp character.hpp
	g++ -c character.cpp

0vampire.o: 0vampire.cpp 0vampire.hpp
	g++ -c 0vampire.cpp

1barbarian.o: 1barbarian.cpp 1barbarian.hpp
	g++ -c 1barbarian.cpp

2bluemen.o: 2bluemen.cpp 2bluemen.hpp
	g++ -c 2bluemen.cpp

3medusa.o: 3medusa.cpp 3medusa.hpp
	g++ -c 3medusa.cpp

4harrypotter.o: 4harrypotter.cpp 4harrypotter.hpp
	g++ -c 4harrypotter.cpp

tournament.o: tournament.cpp tournament.hpp
	g++ -c -std=c++0x tournament.cpp

lineup.o: lineup.cpp lineup.hpp
	g++ -c -std=c++0x lineup.cpp

loserBracket.o: loserBracket.cpp loserBracket.hpp
	g++ -c -std=c++0x loserBracket.cpp
clean: 
	rm *.o p4

