#include <iostream>
#include <string>
using namespace std;
class NSX 
{
    string tenNSX;
    string DiaChi;

public:
    void nhap();
    void xuat();
    friend class HANG;
};

class DATE 
{
    int ngay, thang, nam;

public:
    void nhap();
    void xuat();
    friend class TIVI;
};

class HANG 
{
    string tenHang;
    NSX x;
    float dongia;

public:
    void nhap();
    void xuat();
    HANG();
    friend class NSX;
};

class TIVI 
{
    float kichthuoc;
    DATE a;
    HANG b;

public:
    void nhap();
    void xuat();
    TIVI();
    friend class DATE;
    friend class HANG;
};

void NSX::nhap() 
{
    cout << "Nhap Ten NSX: ";
    getline(cin, tenNSX);
    cout << "Dia chi: ";
    getline(cin, DiaChi);
}

void NSX::xuat() 
{
    cout << "Ten NSX: " << tenNSX << endl;
    cout << "Dia chi: " << DiaChi << endl;
}

void DATE::nhap() 
{
    cout << "Nhap ngay, thang, nam: ";
    cin >> ngay >> thang >> nam;
}

void DATE::xuat() 
{
    cout << "Ngay Thang Nam: " << ngay << " " << thang << " " << nam << endl;
}

void HANG::nhap() 
{
    cout << "Nhap Ten Hang: ";
    getline(cin, tenHang);
    x.nhap();
    cout << "Nhap don gia: ";
    cin >> dongia;
}

void HANG::xuat() 
{
    cout << "Ten Hang: " << tenHang << endl;
    x.xuat();
    cout << "Don Gia: " << dongia << endl;
}

HANG::HANG() 
{
    tenHang = "TV4K";
    x.tenNSX = "Samsung";
    x.DiaChi = "Ha Noi";
    dongia = 300;
}

void TIVI::nhap() 
{
    b.nhap();
    cout << "Nhap kich thuoc: ";
    cin >> kichthuoc;
    a.nhap();
}

void TIVI::xuat() 
{
    b.xuat();
    cout << "Kich Thuoc: " << kichthuoc << endl;
    a.xuat();
}

TIVI::TIVI() 
{
    kichthuoc = 34;
    a.ngay = 12;
    a.thang = 12;
    a.nam = 2005;
}

int main() 
{
    TIVI o;
    cout <<"\t-----Phuong Thuc Khoi Tao-----" << endl;
    o.xuat();
    cout <<"\t==========Nhap Thong Tin cua TIVI==========" << endl;
    o.nhap();
    cout <<"\t==========Thong Tin cua TIVI==========" << endl;
    o.xuat();
    return 0;
}
