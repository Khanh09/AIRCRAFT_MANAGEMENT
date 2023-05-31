#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "KhachHang.h"
using namespace std;

class QuanLiKhachHang {
private:
	int MaxIndex() {
		if (arr.size() == 0) return 0;
		int max = arr[0].getStt();
		for (int i = 0; i < arr.size(); i++) {
			if (max < arr[i].getStt()) max = arr[i].getStt();
		}
		return max;
	}
public:
	vector<KhachHang> arr;
	int index;
	QuanLiKhachHang() {
		arr = {};
		index = -1;
	}

	void Load() {
		ifstream is("KhachHang.txt");
		KhachHang kh;
		while (is >> kh) {
			arr.push_back(kh);
		}
		is.close();
		index = MaxIndex();
	}

	int Insert(string cmnd, string name) {
		index++;
		KhachHang kh(index, cmnd, name);
		ofstream os("KhachHang.txt", ios::app);
		os << kh;
		os.close();
		Load();
		return index;
	}

	void Delete(int stt) {
		bool flag = false;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i].getStt() == stt) {
				flag = true;
				arr.erase(arr.begin() + i);
				break;
			}
		}
		if (flag) {
			ofstream os("KhachHang.txt");
			for (int i = 0; i < arr.size(); i++) {
				os << arr[i];
			}
			os.close();
		}
	}
};