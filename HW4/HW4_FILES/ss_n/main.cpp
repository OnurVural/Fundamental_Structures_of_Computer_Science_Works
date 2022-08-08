
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>




#include "FlightMap.h"
#include <iostream>
using namespace std;

int main() {

    FlightMap fm( "cityFile.txt", "flightFile.txt" );

    cout << "The list of the cities that HPAir serves is given below:" << endl;

    fm.displayAllCities();
    cout << endl;

    cout << "The cities adjacent to D are:" << endl;
    fm.displayAdjacentCities( "D" );
    cout << endl;

    cout << "The whole flight map is shown below:" << endl;
    fm.displayFlightMap();
    cout << endl;


    fm.findFlights( "J", "T" );
    cout << endl;
    fm.findFlights( "C", "E" );
    cout << endl;
    fm.findLeastCostFlight( "T", "E" );
    cout << endl;
    fm.findLeastCostFlight( "F", "G" );
    cout << endl;
    fm.runFlightRequests( "requestFile.txt" );
    return 0;


}

