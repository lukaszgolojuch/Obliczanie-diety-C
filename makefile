#Deklaracje zmiennych

CC = g++
CFLAGS = -c -Wall

#Koniec deklaracji zmiennych

all: program

program: main.o uzytkownik.o
 
	$(CC) -o program main.o uzytkownik.o

main.o: main.cpp main.hpp uzytkownik.hpp
	$(CC) $(CFLAGS) main.cpp


uzytkownik.o: uzytkownik.cpp uzytkownik.hpp
	$(CC) $(CFLAGS) uzytkownik.cpp

clean:
	-rm -rf *o program 