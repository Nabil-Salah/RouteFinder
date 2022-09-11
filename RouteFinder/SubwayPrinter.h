#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Connection.h"
using namespace std;
class SubwayPrinter
{

public:
    void printDirections(vector<Connection> route) {
        Connection connection = route[0];
        string currentLine = connection.getLineName();
        string previousLine = currentLine;

        cout<<"Start out at " + connection.getStation1().getName() + ".\n";
        cout<<"Get on the " + currentLine + " heading towards " + connection.getStation2().getName() + ".\n";

        for (int i = 1; i < route.size(); i++) {
            connection = route[i];
            currentLine = connection.getLineName();
            if (currentLine == previousLine) {
                cout<<"  Continue past  " + connection.getStation2().getName() + "...\n";
            }
            else {
                cout<<"When you get to " + connection.getStation1().getName() + ", get off the " + previousLine + ".\n";
                cout<<"Switch over to the " + currentLine + ", heading towards " + connection.getStation2().getName() + ".\n";
                previousLine = currentLine;
            }
        }
        cout<<"Get off at " + connection.getStation2().getName() + " and enjoy yourself!\n";
    }
};

