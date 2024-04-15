#include <iostream>
#include <iomanip>
#include <cstring>
#include <math.h>
using namespace std;
class HANG
{
private:
    string ten_hang;
    float don_gia;
    int soluong;
public:
    void nhap();
    void xuat();
     float thanhtien();
};
class PHIEU
{
private:
    string ma_phieu;
    string ngay_lap_phieu;
    HANG x[100];
    int n;
public:
    void nhap();
    void xuat();
    friend class HANG;
};
void HANG::nhap()
{
    cout <<"Nhap Ten Hang:";            fflush(stdin);          getline(cin,ten_hang);
    cout <<"Nhap don gia:";                                     cin >> don_gia;
    cout <<"Nhap so luong:";                                    cin >> soluong;
}
void HANG::xuat()
{
    cout << setw(20) <<"Ten Hang" << setw(20) <<"Don Gia" << setw(20) << "So Luong" << setw(20) << "Thanh Tien" << endl;
    cout << setw(19) << ten_hang << setw(20) << don_gia << setw(20) << soluong << setw(20) << thanhtien()<< endl;
}
float HANG::thanhtien()
{
    return don_gia * soluong;
}

void PHIEU::nhap()
{
    // cout << setw(50) <<"PHIEU MUA HANG"<< endl;
    cout <<"Nhap ma phieu:";               fflush(stdin);       getline(cin,ma_phieu);
    cout <<"Nhap Ngay lap phieu:";         fflush(stdin);       getline(cin,ngay_lap_phieu);
    cout <<"Nhap so luong hang:";                               cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        x[i].nhap();
    }
}
void PHIEU::xuat()
{
    // cout << setw(50) <<"PHIEU MUA HANG"<< endl;
    cout << setw(21) <<"Ma Phieu:" << ma_phieu << setw(40) <<"Ngay Lap Phieu:" <<ngay_lap_phieu << endl;
    
    for(int i = 0 ; i < n ; i++)
    {
        x[i].xuat();
    }
    float tong = 0;
    for(int i = 0 ; i < n ; i++)
    {
        tong += x[i].thanhtien();
    }
    cout << setw(65) << "Cong thanh tien:" << setw(14) << tong << endl;
}
int main()
{
    PHIEU a;
    a.nhap();
    cout << setw(50) <<"PHIEU MUA HANG"<< endl;
    cout <<"=================================================================================="<< endl;
    a.xuat();
    cout <<"=================================================================================="<< endl;
}
