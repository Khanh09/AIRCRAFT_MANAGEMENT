#pragma once
#include <iostream>
#include <string>
#include "ChuyenDoi.h"

using namespace std;

class KhachHang {
private:
	int iStt;
	string strCMND;
	string strName;
public:
	KhachHang() {
		iStt = -1;
		strCMND = "null";
		strName = "null";
	}

	KhachHang(int stt, string cmnd, string name) {
		iStt = stt;
		strCMND = cmnd;
		strName = name;
	}

	int getStt() { return iStt; }
	string getCMND() { return strCMND; }
	string getName() { return strName; }

	friend istream& operator >> (istream& is, KhachHang& kh) {
		string stt;
		getline(is, stt, ',');
		getline(is, kh.strCMND, ',');
		getline(is, kh.strName);
		kh.iStt = strtoint(stt);
		return is;
	}

	friend ostream& operator << (ostream& os, KhachHang kh){
		os << kh.iStt << "," << kh.strCMND << "," << kh.strName << endl;
		return os;
	}
};