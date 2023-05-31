#pragma once
#include "MayBay.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class QuanLiMayBay {
public:
	LinkedList<MayBay> arr;
	QuanLiMayBay() {
		arr = {};
	}
	
	void Load() {
		ifstream is("MayBay.txt");
		MayBay mb;
		while (is >> mb) {
			arr.Push_Back(mb);
		}
		is.close();
	}
};