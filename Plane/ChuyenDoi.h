#pragma once
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

inline int strtoint(string s) {
	int n = s.length() - 1;
	int num = 0;
	for (int i = n; i >= 0; i--) {
		num += (int)(s[i] - '0') * pow(10, n - i);
	}
	return num;
}

inline void DanhsachMenu() {
	cout << "MENU" << endl;
	cout << "1.Hien thi chuyen bay" << endl;
	cout << "2.Dat ve" << endl;
	cout << "3.Quan li" << endl;
	cout << "4.Thoat" << endl;
	cout << "Chon" << endl;
}

inline void inputDangNhap(string& username, string& password) {
	system("cls");
	cout << "Nhap username:";
	cin >> username;
	cout << "Nhap password: ";
	cin >> password;
	cin.ignore();
}

inline void MenuQuanLi() {
	system("cls");
	cout << "Quan li" << endl;
	cout << "1.Xu li dat ve" << endl;
	cout << "2.Xu li tra ve" << endl;
	cout << "3.Thong ke" << endl;
}

inline void MenuThongKe() {
	system("cls");
	cout << "Menu Thong Ke" << endl;
	cout << "1.Hien thi danh sach khach hang cua 1 chuyen bay" << endl;
	cout << "2.Hien thi danh sach ghe trong 1 chuyen bay" << endl;
	cout << "3.Thong ke so luong chuyen bay cua 1 may bay" << endl;
}