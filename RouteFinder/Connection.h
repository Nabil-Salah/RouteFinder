#pragma once
#include "Station.h"
class Connection
{
private:
	Station station1, station2;
	string lineName;
	int cost;
public:
	Connection() {
		cost = 0;
	}
	Connection(int cost) {
		this->cost = 0;
	}
	Connection(Station station1, Station station2, string lineName, int cost = 0) {
		this->station1 = station1;
		this->station2 = station2;
		this->lineName = lineName;
		this->cost = cost;
	}
	Connection(Connection& connection) {
		this->station1 = connection.getStation1();
		this->station2 = connection.getStation2();
		this->lineName = connection.getLineName();
		this->cost = connection.getCost();
	}
	Connection(const Connection& connection) {
		station1 = connection.station1;
		station2 = connection.station2;
		lineName = connection.lineName;
		cost = connection.cost;
	}
	Connection operator=(Connection& connection) {
		this->station1 = connection.getStation1();
		this->station2 = connection.getStation2();
		this->lineName = connection.getLineName();
		this->cost = connection.getCost();
		return connection;
	}
	bool operator==(Connection& connection) {
		return station1 == connection.getStation1()
			&& station2 == connection.getStation2() && lineName == connection.getLineName();
	}
	Station& getStation1() { return this->station1; }
	Station& getStation2() { return this->station2; }
	string getLineName() { return lineName; }
	int getCost() { return cost; }
};

