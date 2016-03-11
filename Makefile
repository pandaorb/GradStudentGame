CC = g++
CFLAGS = -c

all: project1 project1_test

project1: encounters.o puzzles.o scoreboard.o menu.o system.o project1_demo.o
	$(CC) encounters.o puzzles.o scoreboard.o menu.o system.o project1_demo.o -o project1
encounters.o: encounters.cpp encounters.h
	$(CC) $(CFLAGS) encounters.cpp
puzzles.o: puzzles.cpp puzzles.h
	$(CC) $(CFLAGS) puzzles.cpp
scoreboard.o: scoreboard.cpp scoreboard.h
	$(CC) $(CFLAGS) scoreboard.cpp
menu.o: menu.cpp menu.h
	$(CC) $(CFLAGS) menu.cpp
system.o: system.cpp system.h
	$(CC) $(CFLAGS) system.cpp
project1_demo.o: project1_demo.cpp project1_functions.h
	$(CC) $(CFLAGS) project1_demo.cpp

project1_test: encounters.o puzzles.o scoreboard.o menu.o system.o project1_test.o
	$(CC) encounters.o puzzles.o scoreboard.o menu.o system.o project1_test.o -o project1_test
project1_test.o: project1_test.cpp project1_functions.h

