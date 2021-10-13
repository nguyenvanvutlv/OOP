#include <iostream>
#include <iomanip>
using namespace std;


class NSX{
    char Mansx[30];
    char Tennsx[30];
    char Dcnsx[30];
public:
    void nhap();
    void xuat();
};
void NSX::nhap(){
    cout << "Ma Nha san xuat: "; fflush(stdin); cin.getline(Mansx,30);
    cout << "Ten Nha san xuat: "; fflush(stdin); cin.getline(Tennsx,30);
    cout << "DC Nha san xuat: "; fflush(stdin); cin.getline(Dcnsx,30);
}
void NSX::xuat(){
    cout << left << setw(30) << Mansx << left
    << setw(30) << Tennsx << left << setw(30) << Dcnsx << endl;
}
class HANG{
    char Mahang[30];
    char Tenhang[30];
    NSX x;
public:
    void nhap();
    void xuat();
};
void HANG::nhap(){
    cout << "Nhap Ma Hang: "; fflush(stdin); cin.getline(Mahang,30);
    cout << "Nhap Ten Hang: "; fflush(stdin); cin.getline(Tenhang,30);
    x.nhap();
}
void HANG::xuat(){
    cout << left << setw(30) << Mahang
    << left << setw(30) << Tenhang  << endl;
    x.xuat();
}
int main()
{
    HANG a; a.nhap(); a.xuat();
}
