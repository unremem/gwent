CC=g++
CXXFLAGS=-std=c++0x -g
LDFLAGS=-g

all: gwent

gwent: gwent.cpp game.o player.o

card_test: card_test.cpp

player_test: player.o player_test.cpp

matchProcess: matchProcess.cpp game.o player.o

initialize: initialize.cpp game.o player.o

player.o: player.hpp

game.o: game.hpp

clean:
	rm -f gwent matchProcess player_test card_test initialize *.o core*
