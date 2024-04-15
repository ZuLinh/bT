#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
class SINHVIEN
{
protected:
    string ma_sv;
    string ten_sv;
    string lop;
    int khoa;
public:
    void nhap();
    void xuat();
};
class MON
{
private:
    string ten_mon;
    int so_trinh;
    float diem;
public:
    void nhap();
    void xuat();
    float diem_trung_binh();
    friend class PHIEU;
};
class PHIEU
{
    SINHVIEN x;
    MON y[100];
    int n;
public:
    void nhap();
    void xuat();
    friend class SINHVIEN;
    friend class MON;
};
void SINHVIEN::nhap()
{
    cout << "\n-Nhap ma sv:";                   fflush(stdin);              getline(cin,ma_sv);
    cout << "\n-Nhap ten sv:";                  fflush(stdin);              getline(cin,ten_sv);
    cout << "\n-Nhap lop:";                      fflush(stdin);              getline(cin,lop);;
    cout << "\n-Nhap khoa:";                                                cin >> khoa;
}
void SINHVIEN::xuat()
{
    cout << setw(5) << "Ma sinh vien:" << setw(10) << ma_sv << setw(20) << "Ten sinh vien:" << setw(5) << ten_sv << endl;
    cout << setw(5) << "Lop:" << setw(10) << lop << setw(20) << "Khoa:" << setw(10) << khoa << endl;
}
void MON::nhap()
{
    cout << "\n-Nhap ten mon:";                    fflush(stdin);               getline(cin,ten_mon);
    cout << "\n-Nhap so trinh:";                                                cin >> so_trinh;
    cout << "\n-Nhap diem:";                                                    cin >> diem;
}
void MON::xuat()
{
    cout << setw(5) << ten_mon << setw(20) << so_trinh << setw(20) << diem << endl;
}
void PHIEU::nhap()
{
    x.nhap();
    cout << "Nhap so mon:";                         cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        y[i].nhap();
    }
}
void PHIEU::xuat()
{
    x.xuat();
    cout << setw(5) <<"Bang diem:"<< endl;
    cout << setw(5) << "Ten mon" << setw(20) << "So trinh" << setw(20) << "Diem" <<endl; 
    for(int i = 0 ; i < n ; i++)
    {
        y[i].xuat();
    }
    float diem_trung_binh = 0;

    int tong_so_trinh = 0;
    for(int i = 0 ; i < n ; i++)
    {
        diem_trung_binh += y[i].diem * y[i].so_trinh;
        tong_so_trinh += y[i].so_trinh;
    }
    if(tong_so_trinh != 0)
    {
        cout << setw(30) << "Diem trung binh:" << setw(10) << diem_trung_binh / tong_so_trinh;
    }
}
int main()
{
    PHIEU a;
    a.nhap();
    a.xuat();
}