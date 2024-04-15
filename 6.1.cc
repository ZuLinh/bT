#include <iostream>
using namespace std;
class PS
{
private:
    int tu;
    int mau;
public:
friend istream& operator >>(istream &x ,PS &y);
friend ostream& operator <<(ostream &x , PS y);
PS operator +(PS y);
PS operator -(PS y);
PS operator *(PS y);
PS operator /(PS y);
};
istream& operator >>(istream &x ,PS &y)
{
    cout <<"Nhap tu so:";
    x >>y.tu;
    cout <<"Nhap mau so:";
    x >> y.mau;
    return x;
}
ostream& operator <<(ostream &x , PS y)
{
    x << y.tu <<"/" <<y.mau;
    return x;
}
PS PS::operator+(PS y)
{
    PS c;
    c.tu = tu *y.mau + y.tu * mau;
    c.mau = mau * y.mau;
    return c;
    
}
PS PS::operator-(PS y)
{
    PS c;
    c.tu = tu *y.mau - y.tu * mau;
    c.mau = mau * y.mau;
    return c;
}
PS PS::operator*(PS y)
{
    PS c;
    c.tu = tu * y.tu;
    c.mau = mau * y.mau;
    return c;
}
PS PS::operator/(PS y)
{
    PS c;
    c.tu = tu * y.mau;
    c.mau = mau * y.tu;
    return c;
}
int main()
{
    PS ps1,ps2,ps3,ps4;
    cin >> ps1;
    cin >>ps2;
    ps3 = ps1 + ps2;
    cout << "cong hai phan so:" << ps3 << endl;
     ps3 = ps1 - ps2;
    cout << "Tru hai phan so:" << ps3 << endl;
    ps3 = ps1 * ps2;
    cout << "Nhan hai phan so:" << ps3<< endl;
    ps3 = ps1 / ps2;
    cout << "Thuong hai phan so:" << ps3<< endl;


}