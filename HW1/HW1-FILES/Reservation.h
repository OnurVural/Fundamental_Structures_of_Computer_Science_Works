//Nurettin Onur VURAL - 21902330
#ifndef RESERVATION_H
#define RESERVATION_H


class Reservation
{
    public:
       Reservation();
       int getReservationNo();
       void setReservationNo(const int rsvNo);
       void setSeatsReserved(const int* newYSeatsReserved, const int sizeOfY, const char* newXSeatsReserved, const int sizeOfX);
       void setAssociatedFlightNo(const int fNo);
       int getAssociatedFlightNo();
       void printSeats();
       int getNumberOfSeats();
       int* getYcoordinateOfSeats();
       char* getXcoordinateOfSeats();
       int getY(int ind);
       char getX(int ind);
       void emptyAll();

    protected:

    private:
       int reservNum;
       int* ySeatsReserved;
       char* xSeatsReserved;
       int ySeatsReservedSize;
       int xSeatsReservedSize;
       int flightNo;

};

#endif // RESERVATION_H

