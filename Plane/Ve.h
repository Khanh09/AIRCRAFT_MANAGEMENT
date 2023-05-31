#pragma once
#include <iostream>
#include <string>
#include "ChuyenDoi.h"
#include "QuanLiKhachHang.h"

using namespace std;

class Ve {
private:
	string strMave;
	string strMachuyenbay;
	int sttGhe;
	int sttHk;
public:
	Ve() {
		strMave = "null";
		strMachuyenbay = "null";
		sttGhe = -1;
		sttHk = -1;
	}

	Ve(string machuyenbay, int soghe, int stthk){
		strMachuyenbay = machuyenbay;
		sttGhe = soghe;
		strMave = strMachuyenbay + to_string(soghe);
		sttHk = stthk;
	}

	string getMave() { return strMave; }
	string getMachuyenbay() { return strMachuyenbay; }
	int getSoghe() { return sttGhe; }
	int getSttHk() { return sttHk; }

	KhachHang getKH() {
		QuanLiKhachHang qlkh;
		qlkh.Load();
		KhachHang kh;
		for (int i = 0; i < qlkh.arr.size(); i++) {
			if (qlkh.arr[i].getStt() == sttHk) {
				return qlkh.arr[i];
			}
		}
		return kh;
	}

	friend istream& operator >> (istream& is, Ve& v){
		string TempSoghe, TempSttHk;
		getline(is, v.strMave, ',');
		getline(is, v.strMachuyenbay, ',');
		getline(is, TempSoghe, ',');
		getline(is, TempSttHk);
		v.sttGhe = strtoint(TempSoghe);
		v.sttHk = strtoint(TempSttHk);
		return is;
	}
	friend ostream& operator << (ostream& os, Ve v) {
		os << v.strMave << "," << v.strMachuyenbay << "," << v.sttGhe << "," << v.sttHk << endl;
		return os;
	}
};