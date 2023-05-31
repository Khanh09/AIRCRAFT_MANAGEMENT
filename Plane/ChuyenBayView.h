#pragma once
#include <vector>
#include <iostream>
#include "ChuyenBay.h"
#include "MayBay.h"
#include <iomanip>
using namespace std;

class ChuyenBayView {
private:
	string HienThiTrangThai(int i) {
		if (i <= 0) {
			return "Da huy";
		}
		else if (i == 1) {
			return "Con ve";
		}
		else if (i == 2) {
			return "Het ve";
		}
		else {
			return "Hoan tat";
		}
	}
public:
	int HienThiCacChuyenBay(LinkedList<ChuyenBay> arr) {
		system("cls");
		cout << setw(15) << right << "Ma chuyen bay" << " |";
		cout << setw(15) << right << "So hieu" << " |";
		cout << setw(15) << right << "Thoi gian" << " |";
		cout << setw(15) << right << "San bay den" << " |";
		cout << setw(15) << right << "Trang thai" << " |";
		cout << setw(15) << right << "Nhan phim" << " |";
		cout << endl;

		for (int i = 0; i < arr.size; i++) {
			cout << setw(15) << right << arr[i].strMachuyenbay << " |";
			cout << setw(15) << right << arr[i].strSohieu << " |";
			cout << setw(15) << right << arr[i].strNgaykhoihanh << " |";
			cout << setw(15) << right << arr[i].strSanbayden << " |";
			cout << setw(15) << right << HienThiTrangThai(arr[i].iTrangthai) << " |";
			cout << setw(15) << right << "Nhan phim " << i << " |";
			cout << endl;
		}
		cout << "Chon: " << endl;
		int a;
		cin >> a;
		return a;
	}

	int HienThiDanhSachVe(LinkedList<ChuyenBay> arr, int a){
		system("cls");
		if (0 <= a && a < arr.size) {
			LinkedList<Ve> arrVe = arr[a].getVES();
			if (arrVe.size == 0) {
				cout << "Chua ai dat ve" << endl;
				system("pause");
				return 0;
			}
			else {
				for (int i = 0; i < arrVe.size; i++) {
					cout << setw(15) << right << arrVe[i].getMave() << " |";
					cout << setw(15) << right << arrVe[i].getMachuyenbay() << " |";
					cout << setw(15) << right << arrVe[i].getSoghe() << " |";
					cout << setw(15) << right << arrVe[i].getSttHk() << " |" << endl;
				}
				system("pause");
			}
		}
		else {
			cout << "Ban nhap khong dung thu tu so" << endl;
			system("pause");
			return 0;
		}
	}

	void HienThiDanhSachKhachHang(LinkedList<KhachHang> arr) {
		system("cls");
		if (arr.size == 0) {
			cout << "Chua co Khach Hang" << endl;
			return;
		}
		cout << setw(15) << "CMND" << " |";
		cout << setw(15) << "TEN" << " |";
		for (int i = 0; i < arr.size; i++) {
			cout << setw(15) << arr[i].getCMND() << " |";
			cout << setw(15) << arr[i].getName() << " |" << endl;
		}
	}

	int  HienThiMayBay(LinkedList<MayBay> arr) {
		for (int i = 0; i < arr.size; i++) {
			cout << setw(15) << right << arr[i].getSohieu() << " |";
			cout << setw(15) << right << arr[i].getSocho() << " |";
			cout << setw(15) << right << "Nhap so " << i << " |" << endl;
		}
		cout << "Chon so:";
		int a;
		cin >> a;
		return a;
	}

	void HienThiCacChuyenBayCua1MayBay(LinkedList<MayBay> arr, int n) {
		if (0 <= n && n < arr.size) {
			string sohieu = arr[n].getSohieu();
			QuanLiChuyenBay qlcb;
			qlcb.Load();
			int dem = 0;
			for (int i = 0; i < qlcb.arr.size; i++) {
				if (qlcb.arr[i].getSohieu() == sohieu && qlcb.arr[i].getTrangthai() == 3) {
					dem++;
				}
			}
			system("cls");
			cout << setw(15) << right << "So hieu" << " |";
			cout << setw(15) << right << "So cho" << " |";
			cout << setw(15) << right << "So chuyen bay" << " |" << endl;

			cout << setw(15) << right << arr[n].getSohieu() << " |";
			cout << setw(15) << right << arr[n].getSocho() << " |";
			cout << setw(15) << right << dem << " |" << endl;
		}
	}
};