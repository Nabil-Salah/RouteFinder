#pragma once
#include "Subway.h"
#include <fstream>
#include <iostream>
using namespace std;
class SubwayLoader
{
private:
	Subway subway;
public:
	SubwayLoader() {
		cout << "creat loader\n";
	}
	Subway& loadFromFile(string fileName) {
		ifstream infile;
		infile.open(fileName);
		string stations;
		while (getline(infile,stations))
		{
			if (stations.size() <= 1)break;
			subway.addStation(stations);
		}
		string lineName;
		while (getline(infile,lineName))
		{
			if (lineName.size() <= 1)break;
			string station1, station2;
			infile >> station1; 
			infile >> station2;
			while (true)
			{
				subway.addConnection(station1, station2, lineName);
				getline(infile, station2);
				if (station1.size() <= 1||station2.size() <=1)break;
				
				station1 = station2;
			}
		}
		infile.close();
		return subway;
	}
};

