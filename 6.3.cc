#include <iostream>
using namespace std;
class PTB2
{
private:
    int a , b , c;
public:
    friend istream& operator >>(istream &x, PTB2 &y);
    friend ostream& operator <<(ostream &x ,  PTB2 y);
    PTB2 operator +(PTB2 y);
};
istream& operator >>(istream &x, PTB2 &y)
{
    cout <<"Nhap a:";
    x>>y.a;
    cout <<"Nhap b:";
    x>>y.b;
    cout <<"Nhap c:";
    x>>y.c;
    return x;
}
ostream& operator <<(ostream &x ,  PTB2 y)
{
    x << y.a <<" x^ +" << y.b <<"x + " << y.c <<  "= 0";
    return x;
}
PTB2 PTB2::operator+(PTB2 y)
{
    PTB2 k;
    k.a = a + y.a;
    k.b = b + y.b;
    k.c = c + y.c;
    return k;
}
int main()
{
    PTB2 e , f,d;
    cin >> e;
    cin >> f;
    d = e + f;
    cout <<"PTB2:" << d;
}