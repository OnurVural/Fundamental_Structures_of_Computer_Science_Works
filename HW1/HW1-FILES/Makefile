# -*- Makefile -*-


RSystem : main.o ReservationSystem.o Flight.o Reservation.o
	g++ main.o ReservationSystem.o Flight.o Reservation.o -o RSystem

ReservationSystem.o: ReservationSystem.cpp Flight.cpp Reservation.cpp
	g++ -c ReservationSystem.cpp

Flight.o: Flight.cpp Reservation.cpp
	g++ -c Flight.cpp

Reservation.o: Reservation.cpp
	g++ -c Reservation.cpp

main.o: main.cpp ReservationSystem.cpp Flight.cpp Reservation.cpp
	g++ -c main.cpp

Remove :
	rm -f ReservationSystem.o Flight.o Reservation.o main.o RSystem
