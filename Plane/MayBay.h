#pragma once
#include <iostream>

using namespace std;

class MayBay {
private:
	string strSohieu;
	int iSocho;
public:
	MayBay() {
		strSohieu = "null";
		iSocho = -1;
	}

	friend istream& operator >> (istream& is, MayBay& mb) {
		is >> mb.strSohieu >> mb.iSocho;
		return is;
	}

	friend ostream& operator << (ostream& os, MayBay mb) {
		os << mb.strSohieu << " " << mb.iSocho << endl;
		return os;
	}

	string getSohieu() { return strSohieu; }
	int getSocho() { return iSocho; }
};