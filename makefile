CC=cc

CCFLAGS= -lstdc++ \
				 -std=c++17 \
				 -lstdc++fs \
				 -Wall \
				 -lsfml-graphics \
				 -lsfml-system \
				 -lsfml-audio \
				 -lsfml-window \
				 -Iinclude/

CSTDFLAGS= -std=c++17 \
					 -Wall \
					 -Wextra \
					 -Iinclude/

TARGETS=main.o \
				Window.o \
				asset.o \
				IslandType.o \
				log.o \
				MouseType.o

all: $(TARGETS)
	$(CC) $(TARGETS) $(CCFLAGS)

main.o:
	$(CC) $(CSTDFLAGS) src/main.cpp -c

Window.o:
	$(CC) $(CSTDFLAGS) src/Window.cpp -c

asset.o:
	$(CC) $(CSTDFLAGS) src/asset.cpp -c

IslandType.o:
	$(CC) $(CSTDFLAGS) src/IslandType.cpp -c

log.o:
	$(CC) $(CSTDFLAGS) src/log.cpp -c

MouseType.o:
	$(CC) $(CSTDFLAGS) src/MouseType.cpp -c

rm:
	rm -v $(TARGETS) *.out
