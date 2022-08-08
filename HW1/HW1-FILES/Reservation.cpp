//Nurettin Onur VURAL - 21902330
#include "Reservation.h"
#include <iostream>

using namespace std;

Reservation::Reservation()
{
    reservNum = 0;
    ySeatsReserved = NULL;
    xSeatsReserved = NULL;
    ySeatsReservedSize = 0;
    xSeatsReservedSize = 0;
    flightNo = 0;
}

int Reservation::getReservationNo() {
    return reservNum;
}
void Reservation::setReservationNo(const int rsvNo) {
    reservNum = rsvNo;
}

void Reservation::setAssociatedFlightNo(const int fNo) {
    flightNo = fNo;
}
int Reservation::getAssociatedFlightNo() {
    return flightNo;
}

void Reservation::setSeatsReserved(const int* newYSeatsReserved, const int sizeOfY, const char* newXSeatsReserved, const int sizeOfX) {


    if (ySeatsReservedSize != 0){
       int* temp1 = ySeatsReserved;
       delete [] temp1;
    }

    if (xSeatsReservedSize != 0){
       char* temp2 = xSeatsReserved;
       delete [] temp2;
    }

    ySeatsReservedSize = sizeOfY;
    ySeatsReserved = new int[sizeOfY];
    for (int i = 0; i < sizeOfY; i++)
        ySeatsReserved[i] = newYSeatsReserved[i];

    xSeatsReservedSize = sizeOfX;
    xSeatsReserved = new char[sizeOfX];
    for (int i = 0; i < sizeOfX; i++) {
        xSeatsReserved[i] = newXSeatsReserved[i];
    }
}

void Reservation::printSeats() {
    for (int i = 0; i < xSeatsReservedSize; i++) {
        cout << ySeatsReserved[i] << xSeatsReserved[i] << " ";
    }
}

int Reservation::getNumberOfSeats() {
    return ySeatsReservedSize;
}
int* Reservation::getYcoordinateOfSeats() {
    return ySeatsReserved;
}
char* Reservation::getXcoordinateOfSeats() {
    return xSeatsReserved;
}

int Reservation::getY(int ind){
   return ySeatsReserved[ind];
}

char Reservation::getX(int ind){
   return xSeatsReserved[ind];
}

void Reservation::emptyAll(){
if (ySeatsReserved)
    delete []ySeatsReserved;
if (xSeatsReserved)
    delete [] xSeatsReserved;
ySeatsReservedSize = 0;
xSeatsReservedSize = 0;
}
