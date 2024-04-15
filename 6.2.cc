#include <iostream>
using namespace std;
class SOPHUC
{
    private:
    float thuc;
    float ao;
    public:
    friend istream& operator>> (istream &x , SOPHUC &y);
    friend ostream& operator<<(ostream &x , SOPHUC y);
    SOPHUC();
    SOPHUC(float x , float y);
    SOPHUC operator + (SOPHUC y);
    SOPHUC operator - (SOPHUC y);

};
SOPHUC::SOPHUC()
{
    thuc = ao = 0;
}
SOPHUC::SOPHUC(float x , float y)
{
    thuc = x;
    ao = y;
}
istream& operator>> (istream &x , SOPHUC &y)
{
    cout <<"Nhap Phan thuc:";
    x >> y.thuc;
     cout <<"Nhap Phan thuc:";
    x >>  y.ao;
    return x;
}
ostream& operator<< (ostream &x, SOPHUC y) {
    x << y.thuc << " + i*" << y.ao << endl;
    return x;
}

SOPHUC SOPHUC::operator +(SOPHUC y)
{
    SOPHUC tg;
    tg.thuc = thuc + y.thuc;
    tg.ao = ao + y.ao;
    return tg;
}
SOPHUC SOPHUC::operator -(SOPHUC y)
{
    SOPHUC tg;
    tg.thuc = thuc - y.thuc;
    tg.ao = ao - y.ao;
    return tg;
}
int main()
{
    SOPHUC a,b,c,d;
    cin >> a;
    cin >>b;
    c = a+b;
   cout <<"Tong hai so phuc:" << c;
    d= a - b;
   cout <<"Hieu hai so phuc:" << d;
}