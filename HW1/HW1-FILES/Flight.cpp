//Nurettin Onur VURAL - 21902330
#include "Flight.h"
#include "Reservation.h"
#include <iostream>

using namespace std;

Flight::Flight(){
    no = 0;
    row = 0;
    rowSeatNumber = 0;

    yFilledPntr = NULL;
    xFilledPntr = NULL;
    seatPntr = NULL;

    yFilledPntrSize = 0;
    xFilledPntrSize = 0;

    reservations = NULL;
    rsrvSize = 0;
}
Flight::Flight(const int fno, const int frow, const int frowSeatNumber){
    no = fno;
    row = frow;
    rowSeatNumber = frowSeatNumber;

    seatPntr = NULL;
    yFilledPntr = NULL;
    xFilledPntr = NULL;
    yFilledPntrSize = 0;
    xFilledPntrSize = 0;

    reservations = NULL;
    rsrvSize = 0;
}

int Flight::getFlightNo(){
    return no;
}

int Flight::getFlightRow(){
    return row;
}
int Flight::getFlightRowSeatNo(){
    return rowSeatNumber;
}
void Flight::setFlightNo(const int fno){
    no = fno;
}
void Flight::setFlightRow(const int frow){
    row = frow;
}
void Flight::setFlightRowSeatNo(const int frowSeatNumber){
    rowSeatNumber = frowSeatNumber;
}

int Flight::giveEmphtySeatNo(){
  return (row * rowSeatNumber) - yFilledPntrSize;
}

void Flight::fillSeat(const int ycord, const char xcord){

    int *temp1 = yFilledPntr;
    char *temp2 = xFilledPntr;

    yFilledPntr = new int[ yFilledPntrSize + 1];
    xFilledPntr = new char[ xFilledPntrSize + 1];

    for (int i = 0; i < yFilledPntrSize; i++)
       yFilledPntr[i] = temp1[i];

    for (int j = 0; j < xFilledPntrSize; j++)
       xFilledPntr[j] = temp2[j];

    yFilledPntrSize++;
    xFilledPntrSize++;

    yFilledPntr[yFilledPntrSize-1]  = ycord;
    xFilledPntr[xFilledPntrSize-1]  = xcord;

    delete[] temp1; //to avoid from memory leak
    delete[] temp2; //to avoid from memory leak
}

void Flight::emptySeat(const int ycord, const char xcord){
   bool found = false;
   int target;
   int a2;

   for (int i = 0; i < yFilledPntrSize; i++){
        a2 = xFilledPntr[i];
      if (yFilledPntr[i] == ycord && a2 == xcord){
         found = true;
         target = i;
      }
   }
    if (found){

    int *temp1 = yFilledPntr;
    char *temp2 = xFilledPntr;

    if (yFilledPntrSize == 1 || xFilledPntrSize == 1)
    {
       yFilledPntr = NULL;
       xFilledPntr = NULL;
    }
    else
    {

       yFilledPntr = new int[ yFilledPntrSize - 1];
       xFilledPntr = new char[ xFilledPntrSize - 1];
       for ( int j = 0; j < target; j++) //first elements until target(the desired location) is deep copied
          yFilledPntr[j] = temp1[j];
       for ( int k = target + 1; k < yFilledPntrSize; k++) //proceeding elements disregarding target(the desired location) is deep copied
          yFilledPntr[k-1] = temp1[k];

       for ( int j = 0; j < target; j++) //first elements until target(the desired location) is deep copied
          xFilledPntr[j] = temp2[j];
       for ( int k = target + 1; k < xFilledPntrSize; k++) //proceeding elements disregarding target(the desired location) is deep copied
          xFilledPntr[k-1] = temp2[k];

    }
       yFilledPntrSize--;
       delete [] temp1; //to avoid memory leak
       xFilledPntrSize--;
       delete [] temp2; //to avoid memory leak
    }



}
void Flight::emptySeats(const int* ycord, const char* xcord, const int seatSize){
    int count = 0;
   do{
    for (int i = 0; i < yFilledPntrSize; i++){
      if (yFilledPntr[i] == ycord[count] && xFilledPntr[i] == xcord[count]){
         emptySeat(yFilledPntr[i], xFilledPntr[i]);
         count++;
      }
    }
   }while (count < seatSize );

}
bool Flight::isFull(const int ycord, const char xcord){

    int a1 = xcord;
    int a2;

   for (int i = 0; i < yFilledPntrSize; i++){
        a2 = xFilledPntr[i];
      if (yFilledPntr[i] == ycord && a2 == a1 )
         return true;
   }
   return false;
}

void Flight::printSeats(){
seatPntr = new char[27];
for (int i = 0; i < 27; i++)
    seatPntr[i] = 65 + i;

for ( int i = 0; i < rowSeatNumber; i++)
    cout << seatPntr[i] << " ";

cout << endl;

for ( int k = 1; k <= row; k++ ){
    cout << k << " " ;
    for ( int j = 0; j < rowSeatNumber; j++ ){
       if ( isFull( k  , 65+j) ){
          cout <<  "x "  ;}
       else{
            cout <<  "o "  ;}
    }
       cout << endl;
}
   delete [] seatPntr;
}

void Flight::emptyAllSeats(){
    if (yFilledPntr)
        delete [] yFilledPntr;
    if (xFilledPntr)
       delete [] xFilledPntr;
    yFilledPntrSize = 0;
    xFilledPntrSize = 0;
}


