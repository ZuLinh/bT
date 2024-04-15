#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class TRUONG
{
protected:
    string ma_truong;
    string ten_truong;
    string dia_chi;
public:
    void nhap();
    void xuat();
};
void TRUONG::nhap()
{
    cout<<"\nMa truong: ";                fflush(stdin);              getline(cin,ma_truong);
    cout<<"\nTen truong: ";               fflush(stdin);              getline(cin,ten_truong);
    cout<<"\nNgay TL: ";                  fflush(stdin);              getline(cin,dia_chi);
}
void TRUONG::xuat()
{
    cout <<setw(30)<<"TRUONG" << endl;
    cout << setw(30) << "Ma Truong " << setw(30) << "Ten Truong " << setw(30) << "Dia Chi "<< endl;
    cout << setw(25) <<  ma_truong   << setw(30) <<  ten_truong   << setw(30) <<  dia_chi;
}
class KHOA
{
    string ma_khoa;
    string ten_khoa;
    string truong_khoa;
    friend class TRUONGDH;
};
class BAN
{
    string ma_ban;
    string ten_ban;
    string ngay_thanh_lap;
    friend class TRUONGDH;
};
class TRUONGDH:private TRUONG
{
    KHOA x[100];
    int ds_khoa;
    BAN y[100];
    int ds_BAN;
public:
    void nhap();
    void xuat();
};
void TRUONGDH::nhap()
{
    TRUONG::nhap();
    cout << "\nNhap so khoa:";
    cin >> ds_khoa;
    cout << "Nhap danh sach cac khoa " << ds_khoa << endl;
    for(int i = 0 ; i <  ds_khoa ; i++)
    {
        cout << "Nhap ma khoa:";        fflush(stdin);      getline(cin,x[i].ma_khoa); 
        cout << "Nhap ten khoa:";       fflush(stdin);      getline(cin,x[i].ten_khoa);
        cout << "Nhap truong khoa";     fflush(stdin);      getline(cin,x[i].truong_khoa);
    }
    cout << "\nNhap so ban:";
    cin >> ds_BAN;
    cout << "Nhap danh sach cac khoa " << ds_BAN << endl;
    for(int i = 0 ; i < ds_BAN ; i++)
    {
        cout << "\nNhap ma ban:";             fflush(stdin);         getline(cin,y[i].ma_ban);
        cout << "\nNhap ten ban:";            fflush(stdin);         getline(cin,y[i].ten_ban);
        cout << "\nNhap ngay thanh lap:";     fflush(stdin);         getline(cin,y[i].ngay_thanh_lap);
    }
}
void TRUONGDH::xuat()
{
    TRUONG::xuat();
    cout << endl;
     cout <<"---------------------------------------------------------------------------------------" << endl;
     cout << setw(30) << "Ma Khoa " << setw(30) << "Ten Khoa " << setw(30) << "Truong Khoa"<< endl;
    for(int i = 0 ; i < ds_khoa ; i++)
    {
        cout << setw(25) << x[i].ma_khoa << setw(30) << x[i].ten_khoa << setw(30) << x[i].truong_khoa << endl;
    }
    
    cout << endl;
    cout <<"---------------------------------------------------------------------------------------" << endl;
    cout << setw(30) << "Ma Ban " << setw(30) << "Ten Ban " << setw(30) << "Ngay Thanh Lap"<< endl;
    for(int i = 0 ; i < ds_BAN ; i++)
    {
        cout << setw(25) << y[i].ma_ban << setw(30) << y[i].ten_ban << setw(30) << y[i].ngay_thanh_lap<<endl;
    }
}
int main()
{
    TRUONGDH a;
    a.nhap();
    a.xuat();
}