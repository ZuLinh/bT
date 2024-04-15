#include <iostream>
using namespace std;
class NGUOI
{
    string name;
    string birth;
    string address;
public:
    void nhap();
    void xuat();
};
class GIANGVIEN
{
    string name_GV;
    string date_GV;
public:
    void nhap();
    void xuat();
};
class HOCSINH
{
    string lop;
    float diem;
    NGUOI x;
public:
    void nhap();
    void xuat();
    // HOCSINH();
    friend class NGUOI;
};
class TRUONG
{
    string name_TR;
    string date_TR;
public:
    void nhap();
    void xuat();
};
void TRUONG::nhap()
{
    fflush(stdin);
    cout <<"Nhap Ten Truong:";
    getline(cin,name_TR);
    fflush(stdin);
    cout <<"Nhap Date:";
    getline(cin,date_TR);
}
void TRUONG::xuat()
{
    cout <<"Ten Truong:" << name_TR << endl;
    cout <<"Date:" << date_TR << endl;
}
void GIANGVIEN::nhap()
{
    fflush(stdin);
    cout <<"Nhap ten GV:";
    getline(cin,name_GV);
    fflush(stdin);
    cout <<"Nhap date:";
    getline(cin,date_GV);

}
void ::GIANGVIEN::xuat()
{
    cout <<"Ten GV:" << name_GV << endl;
    cout <<"Date GV:" << date_GV << endl;

}
void HOCSINH::nhap()
{
    x.nhap();
    cout <<"Nhap lop hoc:";
    getline(cin,lop);
    cout <<"Nhap diem:";
    cin >> diem;
}
void HOCSINH::xuat()
{
    x.xuat();
    fflush(stdin);
    cout <<"Ten lop hoc:" << lop << endl;
    cout <<"Diem :" << diem << endl;
}
void NGUOI::nhap()
{
    fflush(stdin);
    cout <<"Nhap ten hoc sinh:";
    getline(cin,name);
    fflush(stdin);
    cout <<"Nhap birth :";
    getline(cin,birth);
    fflush(stdin);
    cout <<"Nhap dia chi:";
    getline(cin,address);
}
void NGUOI::xuat()
{
    cout <<"==================================="<< endl;
    cout <<"Ten Hoc Sinh:" << name << endl;
    cout <<"Birth :" << birth << endl;
    cout <<"Address:" << address << endl;
    cout <<"==================================="<< endl;
}
int main()
{
    HOCSINH a;
    a.nhap();
    a.xuat();
}
