#include <iostream>
#include "ChuyenDoi.h"
#include <queue>
#include "Controller.h"
#include"Linkedlist.h"

#include "QuanLiDangNhap.h"
using namespace std;

int main() {
	LinkedList<Ve> danhsachvecho=LinkedList<Ve>();
	LinkedList<KhachHang> danhsachkhachhangcho = LinkedList<KhachHang>();
	Controller control;
	while (true) {
		system("cls");
		int dem = 0;
		int temp = 0;
		int temp1 = 0;

		DanhsachMenu();

		int a;
		cin >> a;

		switch (a)
		{
		case 1:
			dem = control.HienThiChuyenBay();
			break;
		case 2:
			dem = control.DatVE(danhsachvecho, danhsachkhachhangcho);
			system("pause");
			break;
		case 3:
			temp = control.QuanLi();
			if (temp == 1) {
				control.XuLiDatVe(danhsachvecho, danhsachkhachhangcho);
			}
			else if (temp == 2) {
				control.TraVe();
			}
			else if (temp == 3) {
				temp1 = control.ThongKe();
				if (temp1 == 1) {
					control.ThongKeKhachHang();
				}
				else if (temp1 == 2) {
					control.ThongKeGheTrong();
				}
				else if (temp1 == 3) {
					control.ThongKeMayBay();
				}
			}
			break;
		default:
			dem = -1;
			break;
		}
		if (dem != 0) break;
	}
	return 0;
}