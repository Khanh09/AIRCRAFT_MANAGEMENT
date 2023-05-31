#pragma once
#include <iostream>
#include <string>

using namespace std;

class Admin {
private:
	string userName;
	string password;
public:
	Admin() {
		userName = "";
		password = "";
	}

	bool check(string name, string pass) {
		if (userName == name && password == pass){
			return true;
		}
		return false;
	}

	friend istream& operator >> (istream& is, Admin& ad) {
		getline(is, ad.userName, ',');
		getline(is, ad.password);
		return is;
	}

	friend ostream& operator << (ostream& os, Admin ad) {
		os << ad.userName << "," << ad.password << endl;
		return os;
	}
};