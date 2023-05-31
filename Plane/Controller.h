#pragma once
#include "QuanliChuyenBay.h"
#include "ChuyenBayView.h"
#include "KhachHang.h"
#include <queue>
#include "QuanLiKhachHang.h"
#include "QuanLiDangNhap.h"
#include "QuanLiMayBay.h"
#include "Linkedlist.h"
using namespace std;

class Controller {
public:
	int HienThiChuyenBay() {
		ChuyenBayView view;

		QuanLiChuyenBay qlcb=QuanLiChuyenBay();
		qlcb.Load();

		int n = view.HienThiCacChuyenBay(qlcb.arr);
		n = view.HienThiDanhSachVe(qlcb.arr, n);
		return 0;
	}

	int DatVE(LinkedList<Ve> &queueVe, LinkedList<KhachHang> &queueKH) {
		QuanLiChuyenBay qlcb;
		qlcb.Load();
		//Chon chuyen bay
		ChuyenBayView view;
		int n = view.HienThiCacChuyenBay(qlcb.arr);
		if (0 <= n && n < qlcb.arr.size) {
			ChuyenBay chuyenbay = qlcb.arr[n];
			vector<bool> danhsachghetrong = chuyenbay.getDanhsachGheTrong();
			if (chuyenbay.getTrangthai() == 3 || chuyenbay.getTrangthai() == 0) {
				cout << "Chuyen Bay da hoan tat hoac bi huy. Khong dat duoc ve" << endl;
				return 0;
			}

			string cmnd, name;
			int soghe;
			cout << "CMND: ";
			cin >> cmnd;
			cout << "Name: ";
			cin.ignore();
			getline(cin, name);
			while (true) {
				cout << "So Ghe(Nhap -1 thoat): ";
				cin >> soghe;
				if (soghe == -1) break;
				else if (soghe >= 0 && soghe < danhsachghetrong.size() && danhsachghetrong[soghe] == false) break;
				else cout << "Ghe da duoc dat.Nhap -1 de thoat" << endl;
			}
			if (soghe != -1) {
				cout << "Ve dang cho xu li" << endl;
			}

			KhachHang kh(0, cmnd, name);
			queueKH.Push_Back(new Node<KhachHang>(kh));

			Ve ve(chuyenbay.getMachuyenbay(), soghe, 0);
			queueVe.Push_Back(new Node<Ve>(ve));

			system("pause");
		}
		else {
			cout << "Ban da nhap sai cu phap" << endl;
			system("pause");
			return 0;
		}
		return 0;
	}

	int QuanLi() {
		QuanLiDangNhap qldn;
		qldn.Load();
		string username = "";
		string password = "";
		int i = 0;
		while (true) {
			i++;
			inputDangNhap(username, password);
			if (qldn.DangNhap(username, password)) {
				break;
			}
			if (i >= 3) {
				system("cls");
				cout << "Ban da het luot dang nhap. Chuong trinh da thoat." << endl;
				system("pause");
				return 0;
			}
		}
		MenuQuanLi();
		int a;
		cin >> a;
		return a;
	}

	int XuLiDatVe(LinkedList <Ve> &queueVe, LinkedList<KhachHang> &queueKH){
		if (queueVe.size==0) {
			cout << "Chua co ve cho" << endl;
			system("pause");
			return 0;
		}
		while (!(queueVe.size==0)) {
			system("cls");
			Ve ve = queueVe.front();
			queueVe.PopBack();
			KhachHang kh = queueKH.front();
			queueKH.PopBack();
			cout << ve;
			cout << kh;
			
			QuanLiKhachHang qlkh;
			qlkh.Load();
			int n = qlkh.Insert(kh.getCMND(), kh.getName());

			QuanLiChuyenBay qlcb;
			qlcb.Load();
			ChuyenBay cb;
			for (int i = 0; i < qlcb.arr.size; i++) {
				if (qlcb.arr[i].getMachuyenbay() == ve.getMachuyenbay()) {
					cb = qlcb.arr[i];
					cb.saveVE(n, ve.getSoghe());
					qlcb.Save(cb);

					cout << "Xac nhan dat ve(yes)" << endl;
					system("pause");
					break;
				}
			}
		}
		return 0;
	}

	void TraVe() {
		QuanLiChuyenBay qlcb;
		qlcb.Load();
		ChuyenBayView view;
		int n = view.HienThiCacChuyenBay(qlcb.arr);
		if (0 <= n && n < qlcb.arr.size) {
			ChuyenBay cb = qlcb.arr[n];
			if (cb.getTrangthai() == 3 || cb.getTrangthai() == 0) {
				cout << "Khong tra duoc ve" << endl;
				system("pause");
				return;
			}
			vector<bool> danhsachghetrong = cb.getDanhsachGheTrong();
			int soghe;
			while (true) {
				cout << "So Ghe(nhap -1 thoat): ";
				cin >> soghe;
				if (soghe == -1) break;
				else if (danhsachghetrong[soghe] == true) break;
				else cout << "Ghe chua duoc dat>Nhap -1 thoat" << endl;
			}

			if (soghe == -1) return;

			LinkedList<Ve> arrVe = cb.getVES();
			Ve v;
			for (int i = 0; i < arrVe.size; i++) {
				if (arrVe[i].getSoghe() == soghe) {
					v = arrVe[i];
					break;
				}
			}
			cb.deleteVe(v.getSoghe());
			qlcb.Save(cb);
			QuanLiKhachHang qlhk;
			qlhk.Load();
			qlhk.Delete(v.getSttHk());
			cout << "Da tra ve thanh cong";
		}
		else {
			"So ban chon chua phu hop";
			system("pause");
			return;
		}
	}

	int ThongKe() {
		MenuThongKe();
		int a;
		cin >> a;
		return a;
	}

	int ThongKeKhachHang() {
		system("cls");
		QuanLiChuyenBay qlcb;
		qlcb.Load();
		ChuyenBayView view;
		int n = view.HienThiCacChuyenBay(qlcb.arr);
		if (0 <= n && n < qlcb.arr.size) {
			ChuyenBay cb = qlcb.arr[n];
			ChuyenBayView view;
			view.HienThiDanhSachKhachHang(cb.getKH());
			system("pause");
		}
		else {
			"So ban chon chua phu hop";
			system("pause");
		}
		return 0;
	}

	int ThongKeGheTrong() {
		system("cls");
		QuanLiChuyenBay qlcb;
		qlcb.Load();
		ChuyenBayView view;
		int n = view.HienThiCacChuyenBay(qlcb.arr);
		if (0 <= n && n < qlcb.arr.size) {
			ChuyenBay cb = qlcb.arr[n];
			vector<bool> arrGhetrong = cb.getDanhsachGheTrong();
			cout << "Cac ghe con trong: ";
			for (int i = 0; i < arrGhetrong.size(); i++) {
				if (arrGhetrong[i] == false) {
					cout << i << " ";
				}
			}
			cout << endl;
			system("pause");
		}
		else {
			"So ban chon chua phu hop";
			system("pause");
		}
		return 0;
	}

	void ThongKeMayBay() {
		QuanLiMayBay qlmb;
		qlmb.Load();
		ChuyenBayView view;
		int n = view.HienThiMayBay(qlmb.arr);
		view.HienThiCacChuyenBayCua1MayBay(qlmb.arr, n);
		system("pause");
	}
};