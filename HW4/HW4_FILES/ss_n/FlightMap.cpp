//N.ONUR VURAL - 21902330 - CS201:SEC1
#include "FlightMap.h"
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <cstdlib>
#include <iostream>
using namespace std;

FlightMap::FlightMap( const string cityFile, const string flightFile ){


    cityNum = 0;

    string text;
    string process;
    cityFileName = cityFile;
    flightName = flightFile;

//    cities.open( cityFileName.c_str(), ios_base::in );
//    while ( cities.eof() == false )
//    {
//    getline( cities, text, '\n' );
//      cityStore[cityNum][0] = text;
//      //mark not visited
//      cityStore[cityNum][1] = " ";
//      cityNum++;
//    }
//    //Close the input file stream
//    cities.close();




    cities.open( cityFileName.c_str(), ios_base::in );
    while (  getline( cities, text) )
    {
        stringstream ss(text);
        getline( ss, process, '\n' );
        //cout << "MY LENGTH IS " <<  process.length() << endl;
        cityStore[cityNum][0] = process;
        cityStore[cityNum][1] = " ";
        cityNum++;
    }
    cities.close();








    string line;
    string to, from, fNo, fCost;

    fligthNum = 0;
    flights.open( flightName.c_str(), ios_base::in );
    while (  getline( flights, line) )
    {
        stringstream ss(line);
        getline( ss, to, ',' );
        getline( ss, from, ',' );
        getline(ss,fNo, ',');
        getline(ss,fCost, '\n');
      flightStore[fligthNum][0] = to;
      flightStore[fligthNum][1] = from;
      flightStore[fligthNum][2] = fNo;
      flightStore[fligthNum][3] = fCost;
      fligthNum++;
    }

    flights.close();




}

FlightMap::~FlightMap(){
}

void FlightMap::displayAllCities() const{
   for (int i = 0; i < cityNum; i++)
    cout << cityStore[i][0] << ", " ;
   cout << endl;
}

void FlightMap::displayAdjacentCities( const string cityName ) const{
cout << cityName <<  " -> " ;
for (int i = 0; i < fligthNum; i++){
    if (flightStore[i][0] == cityName )
        cout << flightStore[i][1] << ", " ;
}

}
void FlightMap::displayFlightMap() const{
    for ( int i = 0; i < cityNum; i++){
            displayAdjacentCities(cityStore[i][0]);
            cout << endl;
    }
}

int FlightMap::findIndex(string city)const{
    for ( int i = 0; i < cityNum; i++){
        if ( cityStore[i][0] == city )
            return i;
    }
    return -1;
}

void FlightMap::findFlights( const string deptCity, const string destCity ) const{
    cout << "Request is to fly from " << deptCity << " to " << destCity << endl;
    int pos;
    string visitedOrNot[20];
    int numberOfPaths = 0;


    SearchStack ss;
    ss.push(deptCity);
    pos = findIndex(deptCity);
    visitedOrNot[pos] = "V";

    string topCity = deptCity;
    int index = 0;

    while ( !ss.isEmpty() ){

        if(flightStore[index][0] == topCity && visitedOrNot[findIndex(flightStore[index][1])] != "V" ){
                if (flightStore[index][1] == destCity ){
                        numberOfPaths++;
                        index++;
                        int totalExpense = 0;
                        SearchStack copyStack = ss;
                        SearchStack helper;
                        helper.push(destCity);

                        while (!copyStack.isEmpty()){
                            string first = copyStack.peek();
                            helper.push(first);
                            copyStack.pop();
                        }


                        while(1){
                        string from = helper.peek();
                        helper.pop();
                        if (helper.isEmpty()){break;}

                        string to = helper.peek();
                        string flightnum = giveFNo(from,to);
                        string flightCost= giveFCost(from,to);
                        int flightCostinteger = std::atoi(flightCost.c_str());

                        //int flightCostinteger = stoi(flightCost);
                        cout << "Flight #" << flightnum << " from " << from << " to " << to << "  Cost: " << flightCostinteger << endl;
                        totalExpense = totalExpense + flightCostinteger;
                    }
                    //Display the total cost

                cout << "Total Cost.......... " << totalExpense << " TL " << endl;

                }
                else{
                ss.push(flightStore[index][1]);
                topCity = ss.peek();
                visitedOrNot[findIndex(flightStore[index][1])] = "V";
                index = 0; //return back
                }
        }
        else index++;

        if ( index == fligthNum ){
                ss.pop();
                topCity = ss.peek();
                index = 0;
        }


    }

    if (numberOfPaths == 0)
        cout << "Sorry. HPAir does not fly from from " << deptCity << " to " << destCity << "!" << endl;

}

void FlightMap::findLeastCostFlight( const string deptCity, const string destCity )const{
    cout << "Request is to fly from " << deptCity << " to " << destCity << endl;
    int pos;
    string visitedOrNot[20];
    string markFlightIndex[20];
    int numberOfPaths = 0;
    int leastCost = -1;

    SearchStack ss;
    ss.push(deptCity);
    pos = findIndex(deptCity);
    visitedOrNot[pos] = "V";

    string topCity = ss.peek();
    int index = 0;


    while ( !ss.isEmpty() ){

        if(flightStore[index][0] == topCity && visitedOrNot[findIndex(flightStore[index][1])] != "V" ){
                if (flightStore[index][1] == destCity  ){
                        //&& markFlightIndex[index] != "M"
                        //markFlightIndex[index] = "M";
                        //visitedOrNot[findIndex(flightStore[index][0])] == " ";
                        numberOfPaths++;
                        index++;
                        int totalExpense = 0;
                        SearchStack copyStack = ss;
                        SearchStack helper;
                        helper.push(destCity);

                        while (!copyStack.isEmpty()){
                            string copyItem = copyStack.peek();
                            helper.push(copyItem);
                            copyStack.pop();
                        }


                        while(1){
                        string from = helper.peek();
                        helper.pop();
                        if (helper.isEmpty()){break;}

                        string to = helper.peek();
                        string flightnum = giveFNo(from,to);
                        string flightCost= giveFCost(from,to);
                        int flightCostinteger = std::atoi(flightCost.c_str());
                        cout << "Flight #" << flightnum << " from " << from << " to " << to << "  Cost: " << flightCostinteger << endl;
                        totalExpense = totalExpense + flightCostinteger;
                    }
                    //Display the total cost

                cout << "Total Cost.......... " << totalExpense << " TL " << endl;
                cout << endl;
                if (leastCost < 0 || totalExpense < leastCost ){
                        leastCost = totalExpense;
                }

                }
                else{
                ss.push(flightStore[index][1]);
                topCity = ss.peek();
                visitedOrNot[findIndex(flightStore[index][1])] = "V";
                index = 0; //return back
                }
        }

        else index++;

        if ( index == fligthNum ){
                ss.pop();
                topCity = ss.peek();
                index = 0;
        }
        //else {index++;}


    }


    if (numberOfPaths == 0)
        cout << "Sorry. HPAir does not fly from from " << deptCity << " to " << destCity << "!" << endl;
    else {
        cout << "The least cost path from " << deptCity << " to " << destCity << " is " << leastCost << " TL" << endl;
        cout << endl;
    }

}

void FlightMap::runFlightRequests( const string requestFile )const{

    ifstream inputFile;
    int requestNumber = 0;
    string requestStore[20][2];

    string line;
    string to, from;
    string requestName = requestFile;

    inputFile.open( requestName.c_str(), ios_base::in );
    while (  getline( inputFile, line) )
    {
        stringstream ss(line);
        getline( ss, to, ',' );
        getline( ss, from, '\n' );
        requestStore[requestNumber][0] = to;
        requestStore[requestNumber][1] = from;
        requestNumber++;
    }



    for (int i = 0; i < requestNumber; i++){
            findLeastCostFlight(requestStore[i][0], requestStore[i][1]);
    }

    inputFile.close();

}


void FlightMap::unvisitAll(){

for(int i=0; i < cityNum; i++)
    cityStore[i][1]=" ";
}

void FlightMap::markVisited(string city){
    for(int i=0; i < cityNum; i++){
        if(cityStore[i][0]== city)
            cityStore[i][1]="V";
    }
}


bool FlightMap::isVisted(string city) const{

for(int i=0; i < cityNum; i++){
        if(cityStore[i][0]== city){
            if(cityStore[i][1] == "V")
                return true;
            else
                return false;
        }
}

}

bool FlightMap::isPath(string deptCity, string destCity)const{
    string visitedOrNot[20];
    int numberOfPaths = 0;

    SearchStack ss;
    ss.push(deptCity);
    int pos = findIndex(deptCity);
    visitedOrNot[pos] = "V";

    string topCity = deptCity;
    int index = 0;

    while ( !ss.isEmpty() && topCity != destCity){

        if(flightStore[index][0] == topCity && visitedOrNot[findIndex(flightStore[index][1])] != "V" ){
                ss.push(flightStore[index][1]);
                topCity = ss.peek();
                visitedOrNot[findIndex(flightStore[index][1])] = "V";
                index = 0; //return back
        }
        else index++;

        if ( index == fligthNum ){
                ss.pop();
                topCity = ss.peek();
                index = 0;
        }


    }

    if (ss.isEmpty())
       return false;
    else
        return true;
}


string FlightMap::giveFNo(string from, string to)const{
    for(int i = 0; i < fligthNum; i++){
        if(flightStore[i][0]== from && flightStore[i][1]==to)
        {
            return flightStore[i][2];
        }
    }
}


string FlightMap::giveFCost(string from, string to)const{
    for(int i = 0; i < fligthNum; i++){
        if(flightStore[i][0]== from && flightStore[i][1]==to)
        {
            return flightStore[i][3];
        }
    }

}
