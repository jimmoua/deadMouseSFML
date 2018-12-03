CXX=clang++
CXXFLAGS= -std=c++17 -lstdc++fs -Wall -lsfml-graphics -lsfml-system -lsfml-audio -lsfml-window
CSTDFLAGS= -std=c++17 -Wall
TARGETS=main.o Window.o asset.o IslandType.o log.o MouseType.o

all: $(TARGETS)
	$(CXX) $(TARGETS) $(CXXFLAGS)

main.o:
	$(CXX) ./src/main.cpp -c $(CSTDFLAGS)

Window.o:
	$(CXX) ./src/Window.cpp -c $(CSTDFLAGS)

asset.o:
	$(CXX) ./src/asset.cpp -c $(CSTDFLAGS)

IslandType.o:
	$(CXX) ./src/IslandType.cpp -c $(CSTDFLAGS)

log.o:
	$(CXX) ./src/log.cpp -c $(CSTDFLAGS)

MouseType.o:
	$(CXX) ./src/MouseType.cpp -c $(CSTDFLAGS)

rm:
	rm -v $(TARGETS) *.out
