#pragma once
#include <vector>
#include "ChuyenBay.h"
#include "Linkedlist.h"
using namespace std;

class QuanLiChuyenBay {
public:
	LinkedList<ChuyenBay> arr;
	QuanLiChuyenBay() {
	}
	void Load() {
		ifstream is("ChuyenBay.txt");
		ChuyenBay cb;
		while (is >> cb) {
			arr.Push_Back(new Node<ChuyenBay>(cb));
		}
		is.close();
	}

	void Save(ChuyenBay cb) {
		for (int i = 0; i < arr.size; i++) {
			if (arr[i].getMachuyenbay() == cb.getMachuyenbay()) {
				arr[i] = cb;
				break;
			}
		}
		ofstream os("ChuyenBay.txt");
		for (int i = 0; i < arr.size; i++) {
			os << arr[i];
		}
		os.close();
	}
};