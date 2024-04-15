#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
class NCC
{
protected:
    string ma_NCC;
    string ten_NCC;
    string dia_chi;
public:
    void nhap();
    void xuat();
};
class HANG
{
private:
    string ten_hang;
    float don_gia;
    int so_luong;
public:
    void nhap();
    void xuat();
    float thanh_tien();
};
class PHIEU:public NCC
{
private:
    string ma_phieu;
    string ngay_lap;
    HANG x[100];
    int n;
public:
    void nhap();
    void xuat();
    friend class HANG;
    friend class NCC;
};
void NCC::nhap()
{
    cout <<"\n-Nhap ma NCC:";                  fflush(stdin);           getline(cin,ma_NCC);
    cout <<"\n-Nhap ten NCC:";                 fflush(stdin);           getline(cin,ten_NCC);
    cout <<"\n-Nhap dia chi NCC:";             fflush(stdin);           getline(cin,dia_chi);
}
void NCC::xuat()
{
    cout << setw(19) << "Ma NCC:" << setw(5) << ma_NCC << setw(21) << "Ten NCC:" << setw(5)<< ten_NCC << endl;
    cout << setw(20) << "Dia chi:" << setw(5) << dia_chi << endl;
}
void HANG::nhap()
{
    cout << "\n-Nhap ten hang:";                   fflush(stdin);          getline(cin,ten_hang);
    cout <<"\n-Nhap don gia:";                                              cin >> don_gia;
    cout <<"\n-Nhap so luong:";                                             cin >> so_luong;
}
void HANG::xuat()
{
    cout << setw(17) << ten_hang << setw(20) << don_gia << setw(20) << so_luong << setw(20) << thanh_tien() << endl;
}
float HANG::thanh_tien()
{
    return don_gia * so_luong;
}
void PHIEU::nhap()
{
   cout << "\n-Nhap ma phieu:";                    fflush(stdin);               getline(cin,ma_phieu);
   cout << "\n-Nhap ngay lap:";                    fflush(stdin);               getline(cin,ngay_lap);
   NCC::nhap();
   cout << "Nhap so luong hang:";                 cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        x[i].nhap();
    }
}
void PHIEU ::xuat()
{
    cout << setw(21) << "Ma phieu:" << setw(5) << ma_phieu << setw(20) << "Ngay lap:" << setw(5)<< ngay_lap << endl;
    NCC::xuat();
    cout << setw(20) << "Ten hang" << setw(20) << "Don gia" << setw(20) << "So luong" << setw(20) << "Thanh tien" << endl;
    for(int i = 0 ; i < n ; i++)
    {
        x[i].xuat();
    }
    float tong = 0;
    for(int i = 0 ; i < n ; i++)
    {
        tong += x[i].thanh_tien();
    }
    cout << setw(68) << "Cong thanh tien " << setw(9) << tong << endl;
}
int main()
{
    PHIEU a;
    a.nhap();
    cout << setw(40) <<"PHIEU NHAP HANG"<< endl;
    a.xuat();
}