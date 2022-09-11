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
	bool operator==(const Station s) const{
		if (name.size() != s.name.size())return false;
		int length = name.size();
		int i = 0;
		for (; i < length; i++)
		{
			if (tolower(s.name[i]) != tolower(name[i]))return false;
		}
		return true;
	}
	bool operator>(const Station s) const{
		int length = (s.name < name ? s.name.size() : name.size());
		int i = 0;
		for (; i < length; i++)
		{
			if (tolower(s.name[i]) < tolower(name[i]))return true;
			else if (tolower(s.name[i]) > tolower(name[i]))return false;
		}
		if (s.name.size() == name.size())return false;
		return s.name.size() < name.size();
	}
	bool operator>=(const Station s) const{
		int length = (s.name < name ? s.name.size() : name.size());
		size_t i = 0;
		for (; i < length; i++)
		{
			if (tolower(s.name[i]) < tolower(name[i]))return true;
			else if (tolower(s.name[i]) > tolower(name[i]))return false;
		}
		if (s.name.size() == name.size())return true;
		return s.name.size() < name.size();
	}
	bool operator<=(const Station s) const{
		int length = (s.name < name ? s.name.size() : name.size());
		size_t i = 0;
		for (; i < length; i++)
		{
			if (tolower(s.name[i]) > tolower(name[i]))return true;
			else if (tolower(s.name[i]) < tolower(name[i]))return false;
		}
		if (s.name.size() == name.size())return true;
		return s.name.size() > name.size();
	}
	bool operator<(const Station s) const {
		int length = (s.name < name ? s.name.size() : name.size());
		size_t i = 0;
		for (; i < length; i++)
		{
			if (tolower(s.name[i]) > tolower(name[i]))return true;
			else if (tolower(s.name[i]) < tolower(name[i]))return false;
		}
		if (s.name.size() == name.size())return false;
		return s.name.size() > name.size();
	}
	
};

