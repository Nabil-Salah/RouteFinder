#pragma once
#include <vector>
#include <exception>
#include "Connection.h"
#include <stdexcept>
#include <map>
#include <queue>
class Subway
{
private:
	vector<Station> stations;
	vector<Connection>connections;
	map<Station, vector<pair<Station, int>> >network;
	bool binarySearchStation(Station& s, int l, int r,vector<Station>& stationsSearch) {
		if (r >= l) {
			int mid = l + (r - l) / 2;

			// If the element is present at the middle
			// itself
			if (stationsSearch[mid] == s)
				return true;

			// If element is smaller than mid, then
			// it can only be present in left subarray
			if (stationsSearch[mid] > s)
				return binarySearchStation(s, l, mid - 1,stationsSearch);

			// Else the element can only be present
			// in right subarray
			return binarySearchStation(s, mid + 1, r,stationsSearch);
		}
		return false;
	}
	void addToNetwork(Station& station1, Station& station2, int cost = 1) {
		if (network.find(station1) != network.end()) {
			bool found = false;
			for (size_t i = 0; i < network[station1].size() && !found; i++)
			{
				if (network[station1][i].first == station2)found = true;
			}
			if(!found)network[station1].push_back(make_pair( station2, cost ));
		}
		else {
			network[station1].push_back(make_pair(station2, cost));
		}
	}
	Connection getConnection(string station1Name, string station2Name) {
		Station station1Search{ station1Name }, station2Search{ station2Name };
		for (size_t i = 0; i < connections.size(); i++)
		{
			Station station1 = connections[i].getStation1(),
				station2 = connections[i].getStation2();
			if (station1 == station1Search && station2 == station2Name)return connections[i];
		}
		return NULL;
	}
public:
	Subway() {
		cout << "Subway Created\n";
	}
	Subway(Subway& s) {
		this->connections = s.connections;
		this->stations = s.stations;
		this->network = s.network;
	}
	Subway& operator=(Subway& s) {
		this->connections = s.connections;
		this->stations = s.stations;
		this->network = s.network;
		return s;
	}
	void addStation(string stationName) {
		Station searchStation{ stationName };
		if (!binarySearchStation(searchStation, 0, stations.size() - 1,stations))
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
		return (binarySearchStation(searchStation, 0, stations.size()-1,stations));
	}
	void addConnection(string station1Name, string station2Name, string lineName,int cost = 1) {
		if (hasStation(station1Name) && hasStation(station2Name)) {
			Station station1{ station1Name }, station2{ station2Name };
			addToNetwork(station1, station2);
			addToNetwork(station2, station1);
			Connection connection{ station1,station2,lineName,cost },
						connectionVice{ station2,station1,lineName,cost };
			connections.push_back(connection);
			connections.push_back(connectionVice);
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
	typedef long long ll;
	vector<Connection>getDirections(string startStationName, string dropStationName) {
		if (!hasStation(startStationName) || !hasStation(dropStationName)) {
			throw invalid_argument("Invalid Connection");
		}
		Station start{ startStationName };
		Station end{ dropStationName };
		long long NDijkstra = stations.size()+6;
		long long nDijkstra;
		map<Station, long long> distDijkstra;
		map < Station, Station> parDijkstra;
		for (auto i : stations)
			distDijkstra[i] = 1e9 + 7;
		distDijkstra[start] = 0;
		//  distance node
		priority_queue< pair < ll, Station >, vector<pair < ll, Station >>, greater<pair < ll, Station >> > pq;
		pq.push({ 0,start });
		while (!pq.empty())
		{
			Station node = pq.top().second;ll distance = pq.top().first;
			pq.pop();
			if (distance > distDijkstra[node]) {
				continue;
			}
			for (auto ch : network[node])
			{
				if (distDijkstra[node] + ch.second < distDijkstra[ch.first])
				{
					parDijkstra[ch.first] = node;
					distDijkstra[ch.first] = distDijkstra[node] + ch.second;
					pq.push({ distDijkstra[ch.first],ch.first });
				}
			}
		}
		vector<Connection> route;
		Station stationTrackParent{ dropStationName };
		while (!(stationTrackParent == startStationName)) {
			route.push_back(getConnection(parDijkstra[stationTrackParent].getName(), stationTrackParent.getName()) );
			stationTrackParent = parDijkstra[stationTrackParent];
		}
		reverse(route.begin(), route.end());
		return route;
	}
};

