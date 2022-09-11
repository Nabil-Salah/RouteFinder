#pragma once
#include <vector>
#include <exception>
#include "Connection.h"
#include <stdexcept>
class Subway
{
private:
	vector<Station> stations;
	vector<Connection>connections;
	bool binarySearchStation(Station& s, int l, int r) {
		if (r >= l) {
			int mid = l + (r - l) / 2;

			// If the element is present at the middle
			// itself
			if (stations[mid] == s)
				return true;

			// If element is smaller than mid, then
			// it can only be present in left subarray
			if (stations[mid] > s)
				return binarySearchStation(s, l, mid - 1);

			// Else the element can only be present
			// in right subarray
			return binarySearchStation(s, mid + 1, r);
		}
		return false;
	}
public:
	Subway() {
		cout << "Subway Created\n";
	}
	Subway(Subway& s) {
		this->connections = s.connections;
		this->stations = s.stations;
	}
	Subway& operator=(Subway& s) {
		this->connections = s.connections;
		this->stations = s.stations;
		return s;
	}
	void addStation(string stationName) {
		Station searchStation{ stationName };
		if (!binarySearchStation(searchStation, 0, stations.size() - 1))
		{
			int i = 0;
			for (; i < stations.size(); i++)
			{
				if (searchStation <= stations[i])break;
			}
			if (i >= stations.size())stations.push_back(searchStation);
			else stations.insert(stations.begin() + i, searchStation);
		}
	}
	bool hasStation(string stationName) {
		Station searchStation{ stationName };
		return (binarySearchStation(searchStation, 0, stations.size()-1));
	}
	void addConnection(string station1Name, string station2Name, string lineName) {
		if (hasStation(station1Name) && hasStation(station2Name)) {
			Station station1{ station1Name }, station2{ station2Name };
			Connection connection{ station1,station2,lineName,0 };
			connections.push_back(connection);
		}
		else {
			throw invalid_argument("Invalid Connection");
		}
	}
	bool hasConnection(string station1Name, string station2Name, string lineName) {
		Connection connectionToFind{ station1Name,station2Name,lineName };
		for (size_t i = 0; i < connections.size(); i++)
		{
			if (connections[i] == connectionToFind)return true;
		}
		return false;
	}
};

