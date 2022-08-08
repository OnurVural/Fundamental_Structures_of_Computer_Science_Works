//Nurettin Onur VURAL - 21902330
#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H
#include "Flight.h"
#include "Reservation.h"
#include <exception>

using namespace std;

class ReservationSystem
{
    public:
        ReservationSystem();
        ~ReservationSystem();
        void addFlight( const int flightNo, const int rowNo, const int seatNo );
        void cancelFlight( const int flightNo );
        void showAllFlights();
        void showFlight( const int flightNo );
        int makeReservation( const int flightNo, const int numPassengers,
        const int *seatRow, const char *seatCol );
        void cancelReservation( const int resCode );
        void showReservation( const int resCode );
        bool checkUniqueFlight( Flight* arr, const int flightListSize, const int flightNo);
        bool checkUniqueReservation(Reservation* arr, const int reservationListSize, const int rNo );

    private:
        Flight* data;
        int flightListSize;
        Reservation* reservationArray;
        int numberOfTotalReservations;

};

#endif // RESERVATIONSYSTEM_H

