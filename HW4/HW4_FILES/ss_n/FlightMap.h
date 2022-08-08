//N.ONUR VURAL - 21902330 - CS201:SEC1
#ifndef FLIGHTMAP_H
#define FLIGHTMAP_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <list>
#include "SearchStack.h"
using namespace std;

class FlightMap
{
    public:
        FlightMap( const string cityFile, const string flightFile );
        ~FlightMap();
        void displayAllCities() const;
        void displayAdjacentCities( const string cityName ) const;
        void displayFlightMap() const;
        void findFlights( const string deptCity, const string destCity ) const;
        void findLeastCostFlight( const string deptCity, const string destCity )const;
        void runFlightRequests( const string requestFile )const;

        //helpers
        //--------------------
        void markVisited(string city);
        void unvisitAll();
        bool isVisted(string city) const;
        int findIndex(string city) const;
        bool isPath(string deptCity, string destCity)const;
        string giveFNo(string from, string to)const;
        string giveFCost(string from, string to)const;

    private:

        ifstream cities;
        ifstream flights;

        string cityFileName;
        string flightName;

        //capable of storing 20 cities with info of being visited or not
        string cityStore[20][2];
        int cityNum;

        string flightStore[20][4];
        int fligthNum;

};

#endif // FLIGHTMAP_H

