#pragma once
#include "Admin.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class QuanLiDangNhap {
public:
	vector<Admin> arr;
	void Load() {
		ifstream is("Admin.txt");
		Admin ad;
		while (is >> ad) {
			arr.push_back(ad);
		}
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i];
		}
		is.close();
	}

	bool DangNhap(string user, string pass) {
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i].check(user, pass)) {
				return true;
			}
		}
		return false;
	}
};