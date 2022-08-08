//Nurettin Onur VURAL - 21902330
#ifndef FLIGHT_H
#define FLIGHT_H

#include "Reservation.h"
#include <string>
//class Reservation;
using namespace std;

class Flight
{
    public:
    Flight();
    Flight(const int fno, const int frow, const int frowSeatNumber);
    int getFlightNo();
    int getFlightRow();
    int getFlightRowSeatNo();
    void setFlightNo(const int fno);
    void setFlightRow(const int frow);
    void setFlightRowSeatNo(const int frowSeatNumber);
    int giveEmphtySeatNo();
    bool isFull(const int ycord, const char xcord);
    void fillSeat(const int ycord, const char xcord);
    void emptySeat(const int ycord, const char xcord);
    void emptySeats(const int* ycord, const char* xcord, const int seatSize);
    void emptyAllSeats();
    void printSeats();

    protected:

    private:
    int no;
    int row;
    int rowSeatNumber;

    int* yFilledPntr ;
    char* xFilledPntr;
    int yFilledPntrSize;
    int xFilledPntrSize;

    char* seatPntr;

    Reservation *reservations;
    int rsrvSize;

};

#endif // FLIGHT_H

