#include <iostream>
#include <iomanip>
using namespace std;


class HANG{
    char Mahang[30];
    char TenHang[30];
    float Dongia;
public:
    void nhap();
    void xuat();
};
void HANG::nhap(){
    cout << "Ma Hang : "; fflush(stdin); cin.getline(Mahang,30);
    cout << "Ten Hang: "; fflush(stdin); cin.getline(TenHang,30);
    cout << "Don Gia : "; cin >> Dongia;
}
void HANG::xuat(){
   cout << left << setw(30) << Mahang << left << setw(30)
   << TenHang << left << setw(10) << Dongia << endl;
}


class PHIEU{
    char MaPhieu[30];
    HANG *x;
    int n;
public:
    void nhap();
    void xuat();
};
void PHIEU::nhap(){
    cout << "ma phieu: "; fflush(stdin); cin.getline(MaPhieu,30);
    cout << "Nhap So Luong hang: "; cin >> n;
    x = new HANG[n];
    for(int i = 0;i<n;i++){
        x[i].nhap();
    }
}
void PHIEU::xuat(){
    cout << "Ma Phieu: " << MaPhieu << endl;

    cout << left << setw(30) << "Ma Hang" << left << setw(30)
   << "Ten Hang" << left << setw(10) << "Don Gia" << endl;
   for(int i= 0;i<n;i++){
        x[i].xuat();
   }
}
int main()
{
    PHIEU a;
    a.nhap();
    a.xuat();
}
