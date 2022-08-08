//Nurettin Onur VURAL - 21902330
#include "ReservationSystem.h"
#include "Flight.h"
#include <iostream>
using namespace std;

ReservationSystem::ReservationSystem() {
    data = NULL;
    flightListSize = 0;

    reservationArray = NULL;
    numberOfTotalReservations = 0;
}

ReservationSystem::~ReservationSystem() {

     if (data){
        for (int i = 0; i < flightListSize; i++)
            data[i].emptyAllSeats();
        delete[] data;
     }

     if (reservationArray){
        for (int j = 0; j < numberOfTotalReservations; j++)
            reservationArray[j].emptyAll();
        delete[] reservationArray;
     }
}

bool ReservationSystem::checkUniqueFlight(Flight* arr, const int flightListSize, const int flightNo) {
    for (int i = 0; i < flightListSize; i++)
    {
        if (arr[i].getFlightNo() == flightNo)
            return false;
    }

    return true;
}

bool ReservationSystem::checkUniqueReservation(Reservation* arr, const int reservationListSize, const int rNo ){
    for (int i = 0; i < reservationListSize; i++)
        {
            if (arr[i].getReservationNo() == rNo)
                return false;
        }

        return true;
}
void ReservationSystem::addFlight(const int flightNo, const int rowNo, const int seatNo) {

    if (flightNo > 0 && checkUniqueFlight(data, flightListSize, flightNo))
    {
        if (rowNo > 0 && seatNo > 0) {

            Flight* temp = data;
            data = new Flight[flightListSize + 1];

            for (int i = 0; i < flightListSize; i++)
                data[i] = temp[i];
            flightListSize++;
            data[flightListSize - 1].setFlightNo(flightNo);
            data[flightListSize - 1].setFlightRow(rowNo);
            data[flightListSize - 1].setFlightRowSeatNo(seatNo);
            delete[] temp; //to avoid from memory leak
            cout << "Flight " << flightNo << " has been added " << endl;

        }
        else
            cout << "error, incorrect number entered" << endl;
    }
    else
        cout << "Flight " << flightNo << " already exists" << endl;
}

void ReservationSystem::cancelFlight(const int flightNo) {
    bool found = false;
    int target;

    for (int i = 0; i < flightListSize; i++) {
        if (data[i].getFlightNo() == flightNo) {
            found = true;
            target = i;
            break;
        }
    }
    if (found) {

        data[target].emptyAllSeats();
        Flight* temp = data;

        if (flightListSize == 1) {
            data = NULL;
        }
        else {

            //clear the reservations under flight
            for (int i = 0; i < numberOfTotalReservations; i++) {
                if (reservationArray[i].getAssociatedFlightNo() == flightNo) {

                    reservationArray[i].emptyAll();
                    Reservation* temp2 = reservationArray;
                    if (numberOfTotalReservations == 1)
                    {
                        reservationArray = NULL;
                    }
                    else {
                    reservationArray = new Reservation[numberOfTotalReservations - 1];
                    for (int j = 0; j < i; j++) //first elements until target(the desired location) is deep copied
                        reservationArray[j] = temp2[j];
                    for (int k = i + 1; k < numberOfTotalReservations; k++) //proceeding elements disregarding target(the desired location) is deep copied
                        reservationArray[k - 1] = temp2[k];
                    }
                    numberOfTotalReservations--;
                    delete[] temp2; //to avoid memory leak
                }
            }
                //delete flight

            data = new Flight[flightListSize - 1];
            for (int i = 0; i < target; i++)
                data[i] = temp[i];
            for (int i = target + 1; i < flightListSize; i++)
                data[i - 1] = temp[i];
        }

        flightListSize--; //flight deleted
        delete[] temp; //avoid memory leak


        cout << "Flight " << flightNo << " and all of its reservations are canceled" << endl;
    }
    else { cout << "Flight " << flightNo << " does not exist" << endl; }
}

void ReservationSystem::showAllFlights() {
    if (data == NULL)
        cout << "No flights exist" << endl;
    else {
        cout << "Flights currently operated:" << endl;
        for (int i = 0; i < flightListSize; i++)
            cout << "Flight " << data[i].getFlightNo() << " (" << data[i].giveEmphtySeatNo() << " available seats)" << endl;
    }
}



int ReservationSystem::makeReservation(const int flightNo, const int numPassengers,
    const int* seatRow, const char* seatCol) {

    bool allAvailable = true;

    if (!checkUniqueFlight(data, flightListSize, flightNo))
    {
        for (int i = 0; i < flightListSize; i++)
        {
            if (data[i].getFlightNo() == flightNo)
            {
                for (int j = 0; j < numPassengers; j++)
                {
                    if (data[i].isFull(seatRow[j], seatCol[j]))
                    {
                        allAvailable = false;
                        cout << "Seat ";
                        cout << seatRow[j] << seatCol[j];
                        cout << " is not available." << endl;
                    }
                }
            }
        }

        if (allAvailable)
        {
            for (int i = 0; i < flightListSize; i++)
            {
                if (data[i].getFlightNo() == flightNo)
                {
                    for (int j = 0; j < numPassengers; j++)
                        data[i].fillSeat(seatRow[j], seatCol[j]);
                }
            }

        Reservation* temp = reservationArray;
        reservationArray = new Reservation[numberOfTotalReservations + 1];

        int myNum;
        if (numberOfTotalReservations == 0 )
            myNum = 1;
        else
            myNum = temp[numberOfTotalReservations-1].getReservationNo() + 1;

        for (int i = 0; i < numberOfTotalReservations; i++)
            reservationArray[i] = temp[i];

        numberOfTotalReservations++;
        reservationArray[numberOfTotalReservations - 1].setReservationNo(myNum);
        reservationArray[numberOfTotalReservations - 1].setAssociatedFlightNo(flightNo);
        reservationArray[numberOfTotalReservations - 1].setSeatsReserved(seatRow, numPassengers, seatCol, numPassengers);

        delete [] temp;
        return reservationArray[numberOfTotalReservations - 1].getReservationNo();
        }
        else
            return -1;
    }
    else
    {
        cout << "Flight " << flightNo << " does not exist." << endl;
        return -1;
    }

}

void ReservationSystem::showFlight(const int flightNo) {
    if (checkUniqueFlight(data, flightListSize, flightNo))
        cout << "Flight " << flightNo << " does not exist." << endl;
    else {

        for (int j = 0; j < flightListSize; j++)
        {
            if (data[j].getFlightNo() == flightNo)
            {
                cout << "Flight " << flightNo << " has " << data[j].giveEmphtySeatNo() << " available seats" << endl;
                data[j].printSeats();
            }
        }
    }
}

void ReservationSystem::showReservation(const int resCode) {
    bool found = false;
    int target;
    if (reservationArray == NULL)
        cout << " No reservations are in the system" << endl;
    else {
        for (int i = 0; i < numberOfTotalReservations; i++)
        {
            if (reservationArray[i].getReservationNo() == resCode) {
                found = true;
                target = i;
                break;
            }
        }
        if (found) {
            cout << "Reservations under Code " << resCode << " in Flight " << reservationArray[target].getAssociatedFlightNo() << ": ";
            reservationArray[target].printSeats();
            cout << endl;
        }
        else
            cout << "No reservations under Code " << resCode << endl;
    }
}


void ReservationSystem::cancelReservation(const int resCode) {
    bool found = false;
    int target;

    for (int i = 0; i < numberOfTotalReservations; i++) {
        if (reservationArray[i].getReservationNo() == resCode) {
            found = true;
            target = i;
        }
    }
    if (found) {

        cout << "Reservation for the seats ";
        reservationArray[target].printSeats();
        cout << "is canceled in Flight " << reservationArray[target].getAssociatedFlightNo() << endl;
        for (int i = 0; i < flightListSize; i++) {


            if (data[i].getFlightNo() == reservationArray[target].getAssociatedFlightNo())
            {
                data[i].emptySeats(reservationArray[target].getYcoordinateOfSeats(), reservationArray[target].getXcoordinateOfSeats(), reservationArray[target].getNumberOfSeats());
            }

        }
        Reservation* temp = reservationArray;
        reservationArray[target].emptyAll();
        if (numberOfTotalReservations == 1) {
            reservationArray = NULL;
        }
        else {

            reservationArray = new Reservation[numberOfTotalReservations - 1];
            for (int j = 0; j < target; j++) //first elements until target(the desired location) is deep copied
                reservationArray[j] = temp[j];
            for (int k = target + 1; k < numberOfTotalReservations; k++) //proceeding elements disregarding target(the desired location) is deep copied
                reservationArray[k - 1] = temp[k];
        }
        numberOfTotalReservations--;
        delete[] temp; //to avoid memory leak
    }
    else {
        cout << "No reservations are found under code " << resCode << " to cancel " << endl;
    }
}



