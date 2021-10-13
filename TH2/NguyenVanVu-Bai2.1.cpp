#include <iostream>
#include <iomanip>
using namespace std;

class DATE{
    int D,Y,M;
public:
    void nhap();
    void xuat();
};
void DATE::nhap(){
    cout << "Ngay : "; cin >> D;
    cout << "Thang: "; cin >> M;
    cout << "Nam  : "; cin >> Y;
}

void DATE::xuat(){
    cout << D << "/" << M << "/" << Y << endl;
}
class NHANSU{
    char Manhansu[15];
    char Hoten[30];
    DATE NS;
public:
    void nhap();
    void xuat();
};
void NHANSU::nhap(){
    cout << "Ma nhan Su: "; fflush(stdin); cin.getline(Manhansu,15);
    cout << "Ho Ten    : "; fflush(stdin); cin.getline(Hoten,30);
    NS.nhap();
}
void NHANSU::xuat(){
    cout << "Ma nhan su: " << Manhansu << endl;
    cout << "Ho va Ten : " << Hoten << endl;
    NS.xuat();
}
int main()
{
    NHANSU x;
    x.nhap();
    x.xuat();
}
