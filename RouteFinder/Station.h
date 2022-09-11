#pragma once
#include <string>
#include <algorithm>
using namespace std;
class Station
{
private:
	string name;
public:
	Station() {
		name = "";
	}
	Station(string name) {
		this->name = name;
	}
	Station(Station& s) {
		this->name = s.name;
	}
	Station(const Station& s) {
		this->name = s.name;
	}
	string getName() { return name; }
	void setName(string name) { this->name = name; }

	Station operator=(const Station& s) {
		name = s.name;
		return s;
	}
	Station operator=(Station& s) {
		name = s.name;
		return s;
	}
	bool isequals(const string& a, const string& b)
	{
		return std::equal(a.begin(), a.end(),
			b.begin(), b.end(),
			[](char a, char b) {
				return tolower(a) == tolower(b);
			});
	}
	bool isgreater(const string& a, const string& b)
	{
		return std::equal(a.begin(), a.end(),
			b.begin(), b.end(),
			[](char a, char b) {
				return tolower(a) > tolower(b);
			});
	}
	bool issmaller(const string& a, const string& b)
	{
		return std::equal(a.begin(), a.end(),
			b.begin(), b.end(),
			[](char a, char b) {
				return tolower(a) < tolower(b);
			});
	}
	bool operator==(Station& s) {
		return isequals(s.name, this->name);
	}
	bool operator>(Station& s) {
		return isgreater(s.name, this->name);
	}
	bool operator>=(Station& s) {
		return isgreater(s.name, this->name) || isequals(s.name, this->name);
	}
	bool operator<=(Station& s) {
		return issmaller(s.name, this->name) || isequals(s.name, this->name);
	}
	bool operator<(Station& s) {
		return issmaller(s.name, this->name);
	}

	bool operator>(const string& s) {
		return isgreater(s, this->name);
	}
	bool operator>=(const string& s) {
		return isgreater(s, this->name) || isequals(s, this->name);
	}
	bool operator<=(const string& s) {
		return issmaller(s, this->name) || isequals(s, this->name);
	}
	bool operator<(const string& s) {
		return issmaller(s, this->name);
	}
	bool operator==(const string& s) {
		return isequals(s, this->name);;
	}
};

