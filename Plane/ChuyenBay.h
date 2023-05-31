#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ChuyenDoi.h"
#include "Ve.h"
#include "Linkedlist.h"
using namespace std;

class ChuyenBay {
private:
	string strMachuyenbay;
	string strSohieu;
	string strNgaykhoihanh;
	string strSanbayden;
	int iTrangthai;
	vector<bool> danhsach;
	int socho;
	void setDanhsach(string chuoi) {
		danhsach.clear();
		int n = chuoi.length();
		socho = n;
		for (int i = 0; i < n; i++) {
			if (chuoi[i] == '1') {
				danhsach.push_back(true);
			}
			else {
				danhsach.push_back(false);
			}
		}
	}

	string getDanhsach() {
		string chuoi = "";
		for (int i = 0; i < socho; i++) {
			if (danhsach[i] == true) {
				chuoi.push_back('1');
			}
			else if(danhsach[i] == false) {
				chuoi.push_back('0');
			}
		}
		return chuoi;
	}
public:
	friend class ChuyenBayView;
	ChuyenBay() {
		strMachuyenbay = "null";
		strSohieu = "null";
		strNgaykhoihanh = "null";
		strSanbayden = "null";
		iTrangthai = -1;
		danhsach = {};
		socho = 0;
	}

	string getMachuyenbay() { return strMachuyenbay; }
	vector<bool> getDanhsachGheTrong() { return danhsach; }
	string getSohieu() { return strSohieu; }
	int getTrangthai() { return iTrangthai; }
	void setTrangthai() { 
		if (iTrangthai != 1) return;
		bool flag = false;
		for (int i = 0; i < danhsach.size(); i++) {
			if (danhsach[i] == false) {
				flag = true;
				break;
			}
		}
		if (flag) iTrangthai = 1; else iTrangthai = 3;
	}

	void saveVE(int stthk, int soghe) {
		if (getTrangthai() != 1) {
			cout << "Khong dat duoc ve";
			return;
		}
		if (danhsach[soghe] == false) {
			danhsach[soghe] = true;
			string maveTxt = strMachuyenbay + to_string(soghe) + ".txt";
			ofstream os(maveTxt);
			Ve ve(strMachuyenbay, soghe, stthk);
			os << ve;
			os.close();
		}
		setTrangthai();
	}

	void deleteVe(int sttghe){
		if (danhsach[sttghe] == true) danhsach[sttghe] = false;
	}

	LinkedList<Ve> getVES() {
		LinkedList<Ve> arr;
		for (int i = 0; i < danhsach.size(); i++) {
			if (danhsach[i] == true) {
				Ve ve;
				string maveTxt = strMachuyenbay + to_string(i) + ".txt";
				ifstream is(maveTxt);
				is >> ve;
				is.close();
				arr.Push_Back(ve);
			}
		}
		return arr;
	}

	LinkedList<KhachHang> getKH() {
		LinkedList<Ve> arrVe = getVES();
		LinkedList<KhachHang> arrKH;
		for (int i = 0; i < arrVe.size; i++) {
			arrKH.Push_Back(arrVe[i].getKH());
		}
		return arrKH;
	}

	friend istream& operator >> (istream& is, ChuyenBay& cb) {
		string TempTrangthai, chuoi;
		getline(is, cb.strMachuyenbay, ',');
		getline(is, cb.strSohieu, ',');
		getline(is, cb.strNgaykhoihanh, ',');
		getline(is, cb.strSanbayden, ',');
		getline(is, TempTrangthai, ',');
		getline(is, chuoi);
		cb.iTrangthai = strtoint(TempTrangthai);
		cb.setDanhsach(chuoi);
		return is;
	}

	friend ostream& operator << (ostream& os, ChuyenBay cb) {
		os << cb.strMachuyenbay << "," << cb.strSohieu << "," << cb.strNgaykhoihanh << "," << cb.strSanbayden << "," << cb.iTrangthai << "," << cb.getDanhsach() << endl;
		return os;
	}
};