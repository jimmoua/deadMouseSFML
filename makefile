CXX=clang++
CXXFLAGS= -std=c++17 -Wall -lsfml-graphics -lsfml-system -lsfml-audio -lsfml-window
CSTDFLAGS= -std=c++17 -Wall
TARGETS=main.o Window.o asset.o IslandType.o log.o MouseType.o

all: $(TARGETS)
	$(CXX) $(TARGETS) $(CXXFLAGS)

main.o:
	$(CXX) main.cpp -c $(CSTDFLAGS)

Window.o:
	$(CXX) Window.cpp -c $(CSTDFLAGS)

asset.o:
	$(CXX) asset.cpp -c $(CSTDFLAGS)

IslandType.o:
	$(CXX) IslandType.cpp -c $(CSTDFLAGS)

log.o:
	$(CXX) log.cpp -c $(CSTDFLAGS)

MouseType.o:
	$(CXX) MouseType.cpp -c $(CSTDFLAGS)

rm:
	rm -v $(TARGETS) *.out
