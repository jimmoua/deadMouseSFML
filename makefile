CXX=g++
CXXFLAGS=-std=c++17 -lstdc++fs -lsfml-graphics -lsfml-system -lsfml-audio -lsfml-window -Wall
TARGETS=main.o Window.o asset.o IslandType.o log.o 

all: $(TARGETS)
	g++ $(TARGETS) $(CXXFLAGS)

main.o:
	g++ main.cpp -c $(CXXFLAGS)

Window.o:
	g++ Window.cpp -c $(CXXFLAGS)

asset.o:
	g++ asset.cpp -c $(CXXFLAGS)

IslandType.o:
	g++ IslandType.cpp -c $(CXXFLAGS)

log.o:
	g++ log.cpp -c $(CXXFLAGS)

rm:
	rm -v $(TARGETS)
