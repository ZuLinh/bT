#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <stdlib.h>
#define MAX 100
using namespace std;
class NhanVien
{
protected:
	int id;
    string name;
    int tuoi;
    float luongCB;
	int loai;
public:
    virtual void nhap();
    virtual void xuat();
	float get_luongCB();
    int get_id();
	virtual float tinhluong()
	{
		return 0;
	}
};
int NhanVien:: get_id()
{
    return id;
}
float NhanVien::get_luongCB()
{
	return luongCB;
}

class CongNhan : public NhanVien
{
    float bacluong;
public:
    void nhap();
    void xuat();
	float tinhluong();


};

class QuanLy : public NhanVien
{
    float phucap;
public:
    void nhap();
    void xuat();
	float tinhluong();
	
};

class GiamDoc : public NhanVien
{
public:
    void nhap();
    void xuat();
	float tinhluong();
};

void NhanVien::nhap()
{
    cout <<"==========================" << endl;
    cout << "Nhap Id:";
	cin >> id;
    cin.ignore();
    cout << "Nhap ten: ";
    getline(cin, name);
    cout << "Nhap tuoi: ";
    cin >> tuoi;
    cout << "Nhap luong co ban: ";
    cin >> luongCB;
}

void NhanVien::xuat()
{	
	cout <<"ID:" << id << endl;
    cout << "Name: " << name << endl;
    cout << "Tuoi: " << tuoi << endl;
    cout << "Luong co ban: " << luongCB << endl;
}

void CongNhan::nhap()
{
    NhanVien::nhap();
    cout <<"Nhap bac luong:";
    cin >> bacluong;
}

void CongNhan::xuat()
{
	cout <<"\tCONG NHAN" << endl;
    cout << "******************************" << endl;
    NhanVien::xuat();
    cout <<"Bac luong:" << bacluong << endl;
}
float CongNhan::tinhluong()
{
	return get_luongCB() * luongCB;
}
void QuanLy::nhap()
{
    NhanVien::nhap();
    cout << "Nhap phu cap: ";
    cin >> phucap;
}

void QuanLy::xuat()
{
    cout <<"\tQUAN LY"<< endl;
    cout << "::::::::::::::::::::::::::::" << endl;
    NhanVien::xuat();
    cout << "Phu Cap: " << phucap << endl;
   
}
 float QuanLy::tinhluong()
 {
	return phucap + luongCB;
 }
void GiamDoc::nhap()
{
    NhanVien::nhap();
}

void GiamDoc::xuat()
{
    cout <<"\tGIAM DOC" << endl;
    cout << "--------------------------------------" << endl;
    NhanVien::xuat();
    
}
float GiamDoc::tinhluong()
{
	return luongCB;
}
void xuat_thong_tin_NV(NhanVien *a[], int soluongNV)
{
	cout <<"\t=====DANH SACH NHAN VIEN====="<< endl;
	for(int i = 0 ; i < soluongNV ;i++)
	{
		a[i]->xuat();
        cout <<"Tong Luong:" << a[i]->tinhluong();
		cout << endl;
	}
}
void xuatluong_max(NhanVien *a[], int soluongNV)
{
    int x;
    cout <<"Nhap muc luong:";
    cin >> x;
    cout <<"\tDANH SACH NHAN VIEN CO LUONG TREN " << x << endl;
    for(int i = 0 ; i < soluongNV ;i++)
    {
        if(a[i]->tinhluong() > x)
        {
            a[i]->xuat();
            cout <<"Tong Luong:" << a[i]->tinhluong();
            cout << endl;

        }
    }
}
void sapxep(NhanVien *a[], int soluongNV)
{
    for(int i = 0 ; i < soluongNV - 1; i++)
    {
        for(int j = i + 1 ;  j < soluongNV ;j++)
        {
            if(a[i]->tinhluong() > a[j]->tinhluong())
            {
                swap(a[i],a[j]);
            }
        }
    }
    for(int i = 0 ; i < soluongNV ; i++)
    {
        a[i]->xuat();
       cout <<"Tong Luong:" << a[i]->tinhluong();
        cout << endl;
    }
}
bool kiem_tra_id(NhanVien *a[], int id_check , int soluongNV)
{
    for(int i = 0 ; i < soluongNV ; i++)
    {
        if(a[i]->get_id()== id_check )
        {
            return false;
        }
    }
    return true;
}
void xoa_NV(NhanVien *a[] , int &soluongNV)
{
    int vitri ;
    int vitri_xoa = 1;
    cout <<"Nhap id can xoa:";
    cin >> vitri_xoa;
    for(int i = 0 ; i < soluongNV ; i++)
    {
        if(a[i]->get_id() == vitri_xoa)
        {
            vitri_xoa = i;
            break;
        }
    }
    if(vitri_xoa==-1)
    {
        cout <<"Khong tim thay id muon xoa" << endl;
        return;
    }
    for(int i = vitri_xoa ; i < soluongNV - 1 ; i++)
    {
        a[i] = a[i + 1];
    }
    soluongNV--;
    for(int i = 0 ; i < soluongNV ; i++)
    {
        a[i]->xuat();
        a[i]->tinhluong();
    }
}
void sua_thongtin_NV(NhanVien *a[] , int soluongNV)
{
    int id_sua;
    cout <<"Nhap id can sua:";
    cin >> id_sua;
    bool check = false;
    {
    for(int i = 0 ; i < soluongNV ; i++)
    {
        if(a[i]->get_id() == id_sua)
        {
            check = true;
            a[i]->nhap();
        }
    }
    if(check == false)
    {
        cout <<"Khong tim thay Nhan Vien nao!"<< endl;
    }
    }
}
int main()
{
	NhanVien *a[MAX];
	int luachon;
	int n;
	int soluongNV = 0;
	do
	{
	cout<<"========MENU========"<<endl;
	cout <<"1.Them Nhan vien"<<endl;
	cout <<"2.Hien thi thong tin Nhan Vien" << endl;
	cout <<"3.So luong Nhan vien" << endl;
    cout <<"4.so luong lon hon x"<< endl;
    cout <<"5.sap xep tang dan theo muc luong"<< endl;
    cout <<"6.xoa Nhan Vien theo id" << endl;
    cout <<"7.Sua Nhan Vien theo id" << endl;
	cout<<"===================="<<endl;
	cout <<"Nhap lua chon cua ban:";
	cin >> luachon;
	switch(luachon)
	{
		case 1:
			if(soluongNV < MAX)
			{
				int loaiNV;
				cout <<"====================="<< endl;
				cout <<"1.Cong Nhan"<< endl;
				cout <<"2.Quan Ly" << endl;
				cout <<"3.Giam Doc" << endl;
				cout <<"====================="<< endl;
				cout <<"Nhap lua chon:";
				cin >> loaiNV;
				switch(loaiNV)
				{
					case 1:
                        a[soluongNV] = new CongNhan();
						a[soluongNV]->nhap();
						break;
					case 2:
						a[soluongNV] = new QuanLy();
						a[soluongNV]->nhap();
						break;
					case 3:
						a[soluongNV] = new GiamDoc();
                        a[soluongNV]->nhap();
						break;
						default:
							cout <<"Lua chon khong hop le" << endl;
							break;
				}
				soluongNV++;
				break;
			}
		case 2:
				xuat_thong_tin_NV(a,soluongNV);
                break;
        case 3:
                cout <<"So luong Nhan vien co trong cong ty:" << soluongNV << endl;
                break;
        case 4:
                xuatluong_max(a,soluongNV);
                break;
        case 5:
                sapxep(a,soluongNV);
                break;
        case 6:
                xoa_NV(a,soluongNV);
                break;
        case 7:
                sua_thongtin_NV(a,soluongNV);
                break;
            default:
                cout <<"Lua chon khong hop le!" << endl;
                break;
	}
}while(luachon != 8);
}