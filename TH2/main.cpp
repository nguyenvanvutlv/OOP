#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class PHONGMAY;

class QUANLY{
    char maql[10];
    char tenql[30];
public:
    void nhap();
    void xuat();
};


void QUANLY::nhap(){
    cout << "Ma Quan Ly: ";  fflush(stdin); cin.getline(maql,10);
    cout << "Ten Quan Ly: ";  fflush(stdin); cin.getline(tenql,30);
}
void QUANLY::xuat(){
    cout << left << setw(10) << maql << left << setw(30) << tenql << endl;
}

class MAY{
    char mamay[30];
    char kieumay[30];
    char tinhtrang[50];
public:
    void nhap();
    void xuat();
    friend void FIX(PHONGMAY A);
};

void MAY::nhap(){
    cout << "Ma may     : ";  fflush(stdin); cin.getline(mamay,30);
    cout << "Kieu may   : ";  fflush(stdin); cin.getline(kieumay,30);
    cout << "Tinh trang : ";  fflush(stdin); cin.getline(tinhtrang,50);
}
void MAY::xuat(){
    cout << left << setw(10) << mamay
    << left << setw(30) << kieumay
    << left << setw(50) << tinhtrang << endl;
}


class PHONGMAY{
    char maphong[10];
    char tenphong[30];
    float DienTich;
    QUANLY x;
    MAY *y;
    int n;
public:
    void nhap();
    void xuat();
    friend void FIX(PHONGMAY A);
    friend void FIX_S(PHONGMAY &A);
};
void PHONGMAY::nhap(){
    cout << "Ma Phong : "; fflush(stdin); cin.getline(maphong,10);
    cout << "Ten Phong: "; fflush(stdin); cin.getline(tenphong,30);
    cout << "Dien tich: "; cin >> DienTich;
    x.nhap();
    cout << "Nhap So Luong May: ";
    cin >> n;
    y = new MAY[n];
    for(int i= 0;i<n;i++){

        y[i].nhap();

    }
}
void PHONGMAY::xuat(){
    cout << "Ma Phong: " << maphong <<" \tTen Phong: "<<tenphong << endl;
    cout << "Dien Tich: " << DienTich << endl;
    cout << "Quan Ly: ";x.xuat() ;
    cout << "Cac Loai may: "<< endl;
    cout << left << setw(10) << "Ma May"
    << left << setw(30) << "Kieu may"
    << left << setw(50) << "Tinh Trang" << endl;
    for(int i = 0;i<n;i++){
        y[i].xuat();
    }
}

void FIX(PHONGMAY A){
    for(int i = 0;i<A.n;i++){
        if( strcmp(A.y[i].mamay, "MS001") == 0){
            strcpy(A.y[i].tinhtrang,"Tot");
        }
    }
}
void FIX_S(PHONGMAY &A){
    A.DienTich = 50;
}
int main()
{
    PHONGMAY A;
    A.nhap();
    cout << endl << endl;
    A.xuat();


    /// bonus 1
    FIX(A);
    cout << endl << endl;
    A.xuat();

    /// bonus 2
    cout << endl << endl;
    FIX_S(A);
    A.xuat();

}
