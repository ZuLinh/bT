#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
using namespace std;
class NhanVien
{
protected:
	string nhanvien_kiem_ke;
	string chuc_vu;
public:
	void nhap();
	void xuat();
};
class PHONG
{
private:
	string kiem_ke_tai_phong;
	string ma_phong;
	string truong_phong;
public:
	void nhap();
	void xuat();
};
class TAISAN
{
	string ten_tai_san;
	int so_luong;
	string tinh_trang;
public:
	void nhap();
	void xuat();
	friend class PHIEU;
};
class PHIEU
{
	string ma_phieu;
	string ngay_kiem_ke;
	NhanVien a;
	PHONG b;
	TAISAN c[100];
	int n;
public:
	void nhap();
	void xuat();
	friend class NhanVien;
	friend class PHONG;
	friend class TAISAN;
};
void NhanVien::nhap()
{
	cout << "\n-Nhap Nhan vien kiem ke:";				fflush(stdin);				getline(cin, nhanvien_kiem_ke);
	cout << "\n-Nhap chuc vu:";							fflush(stdin);				getline(cin, chuc_vu);
}
void NhanVien::xuat()
{
	cout << "Nhan vien kiem ke:" << setw(5) << nhanvien_kiem_ke << setw(20) << "Chuc vu:" << setw(5) << chuc_vu << endl;
} 
void PHONG::nhap()
{
	cout << "\n-Nhap kiem ke tai phong:";				fflush(stdin);				getline(cin, kiem_ke_tai_phong);
	cout << "\n-Nhap ma phong:";						fflush(stdin);				getline(cin, ma_phong);
	cout << "\n-Nhap ten truong phong:";				fflush(stdin);				getline(cin, truong_phong);

}
void PHONG::xuat()
{ 
	cout << "Kiem ke tai phong:" << setw(5) << kiem_ke_tai_phong << setw(20) << "Ma phong:" << setw(5) << ma_phong << endl;
	cout << "Truong phong:" << setw(5) << truong_phong << endl;
}
void TAISAN::nhap()
{
	cout << "\n-Nhap ten tai san:";						fflush(stdin);				getline(cin, ten_tai_san);
	cout << "\n-Nhap so luong:";													cin >> so_luong;
	cout << "\n-Nhap tinh trang:";						fflush(stdin);				getline(cin,tinh_trang);
}
void TAISAN::xuat()
{
	cout << ten_tai_san << setw(25) << so_luong << setw(25) << tinh_trang << endl;
}
void PHIEU::nhap()
{
	cout << "\n-Nhap ma phieu:";						fflush(stdin);				getline(cin, ma_phieu);
	cout << "\n-Nhap ngay kiem ke:";					fflush(stdin);				getline(cin, ngay_kiem_ke);
	a.nhap();
	b.nhap();
	cout << "Nhap so luong tai san:";					cin >> n;
	for (int i = 0; i < n; i++)
	{
		c[i].nhap();
	}
}
void PHIEU::xuat()
{
	cout << "Ma phieu:" << setw(5) << ma_phieu << setw(40) << "Ngay kiem ke:" << setw(5) << ngay_kiem_ke << endl;
	a.xuat();
	b.xuat();
	cout << "Ten tai san" << setw(20) << "So luong:" << setw(20) << "Tinhtrang" << endl;
	for (int i = 0; i < n; i++)
	{
		c[i].xuat();
	}
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong += c[i].so_luong;
	}
	cout << "So luong tai san da kiem ke: " << setw(5) << n << setw(20)  << "To so luong :" << setw(5) << tong<< endl;
    
}
int main()
{
PHIEU z;
	z.nhap();
    cout << endl;
	z.xuat();
}