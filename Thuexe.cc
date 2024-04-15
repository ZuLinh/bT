#include <iostream>
#include <string>
#define MAX 1000
using namespace std;
class Xe
{
protected:
    string ten_nguoi_thue;
    float so_gio_thue;
public:
    void nhap();
    void xuat();
};
class XeDap : public Xe
{
public:
    void nhap();
    void xuat();
    float tinh_tien_thue_xe();
};
class XeMay : public Xe
{
private:
    int loai_xe;
    string bien_so;
public:
    void nhap();
    void xuat();
    float tinh_tien_thue_xe();
    int get_loaixe();
};
int XeMay::get_loaixe()
{
    return loai_xe;
}
void Xe::nhap()
{
    fflush(stdin);
    cout << "Nhap Ten Nguoi Thue:";
    getline(cin,ten_nguoi_thue);
    cout << "Nhap so gio thue xe:";
    cin >> so_gio_thue;
}
void Xe::xuat()
{
    cout << "Ten nguoi thue:" << ten_nguoi_thue << endl;
    cout << "So gio thue xe:" << so_gio_thue << endl;
}

void XeDap::nhap()
{
    Xe::nhap();
}
void XeDap::xuat()
{
    Xe::xuat();
}
float XeDap ::tinh_tien_thue_xe()
{
    return 1000 + ((so_gio_thue - 1) * 8000);
}
void XeMay::nhap()
{
    Xe::nhap();
    fflush(stdin);
    cout << "Nhap bien so:";
    getline(cin , bien_so);
    cout << "Nhap loai xe:";
    cin >> loai_xe;
}
void XeMay::xuat()
{
    cout << "Bien so xe:" << bien_so << endl;
    cout << "Loai xe:" << loai_xe << endl;
}
float XeMay::tinh_tien_thue_xe()
{
    int s = 0;
    if(loai_xe == 100)
    {
        s = 150000;
    }
    else
    {
        s = 200000;
    }
    return s  + ((so_gio_thue - 1) * 10000);
}
void xuatThongTinXe(XeDap ds_xedap[], XeMay ds_xemay[], int n, int m) 
{
    cout << "Thong tin cac xe dap:" << endl;
    for(int i = 0; i < n; ++i) {
        cout << "Xe Dap " << i + 1 << ":" << endl;
        ds_xedap[i].xuat();
        cout <<"Tien thue:" << ds_xedap[i].tinh_tien_thue_xe() << endl;
    }
cout << endl;
    cout << "\nThong tin cac xe may:" << endl;
    for(int i = 0; i < m; ++i) {
        cout << "Xe May " << i + 1 << ":" << endl;
        ds_xemay[i].xuat();
        cout <<"Tien thue:" << ds_xemay[i].tinh_tien_thue_xe() << endl;
    }
}
float tong_tien_thue_xe(XeDap ds_xedap[], XeMay ds_xemay[], int n, int m)
{
    int tong = 0;
    for(int i = 0; i < n; ++i) 
    {
        tong = tong + ds_xedap[i].tinh_tien_thue_xe();
    }
    cout << endl;
    for(int i = 0; i < m; ++i) 
    {
       tong = tong + ds_xemay[i].tinh_tien_thue_xe();
    }
    return tong;
}
float tong_tien_xe_may_250(XeMay ds_xemay[] , int m)
{
    float s = 0;
    for(int i = 0 ; i < m ; i++)
            if(ds_xemay[i].get_loaixe()== 250)
            {
                    s = s + ds_xemay[i].tinh_tien_thue_xe();
            }
    return s;
}
int main()
{
    int choice;
    XeDap ds_xedap[MAX];
    int n = 0;
    XeMay ds_xemay[MAX];
    int m = 0;
    
    do
    {
        cout <<"===========================================================" << endl;
        cout << " 1.Nhap thong tin xe dap xe may" << endl;
        cout << " 2.xuat all cac thong tin xe (ca so tien thue)" << endl;
        cout << " 3.Tinh tong so tien cho thue xe dap va xe may" << endl;
        cout << " 4.Xuat tat ca thong tin lien quan den viec thue xe dap" << endl;
        cout << " 5.Tinh tong so tien cho thue xe may loai 250 phan khoi" << endl;
        cout <<"===========================================================" << endl;
        cout << "Nhap lua chon:";
        cin >> choice;
        
        switch(choice)
        {
            case 1:
                int luachon;
                cout <<"------------------------" << endl;
                cout <<"1.Nhap xe dap" << endl;
                cout <<"2.Nhap xe may" << endl;
                cout <<"------------------------" << endl;
                cout << "Lua chon:";
                cin >> luachon;
                
                switch(luachon)
                {
                    case 1:
                        if(n < MAX)
                        {
                            XeDap x;
                            x.nhap();
                            ds_xedap[n] = x;
                            n++;
                        }
                        else
                        {
                            cout <<"Danh sach da day!!"<< endl;
                        }
                        break;

                    case 2:
                        if(m < MAX)
                        {
                            XeMay y;
                            y.nhap();
                            ds_xemay[m] = y;
                            m++;
                        }
                        else
                        {
                            cout <<"Danh sach da day!!"<< endl;
                        }
                        break;
                        
                    default:
                        cout <<"Lua chon khong hop le!!!" << endl;
                        break;
                }
                break;
                
            case 2:
                xuatThongTinXe( ds_xedap, ds_xemay, n,  m);
                break;
            case 3:
                cout <<"Tong tien thue:" << tong_tien_thue_xe(ds_xedap,ds_xemay,n,m) << endl;
                break;
            case 4:
                cout <<"\tTHONG TIN LIEN QUAN DEN XE DAP"<< endl;
                for(int i = 0 ; i < n ; i++)
                {
                    cout << "Xe Dap " << i + 1 << ":" << endl;
                    ds_xedap[i].xuat();
                    cout <<"Tien thue:" << ds_xedap[i].tinh_tien_thue_xe() << endl;
                }
                break;
            case 5:
                cout << "Tong so tien cho loai xe may 250 phan khoi:" << tong_tien_xe_may_250(ds_xemay,m) << endl;
                break;
        }
    } while(choice != 6);
    
    return 0;
}

