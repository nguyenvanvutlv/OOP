#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
class LOPHOC;

class NGUOI{

protected:
    char Hoten[30];
    char NgaySinh[15];
    char QueQuan[30];
public:
    void nhap();
    void xuat();
};
void NGUOI::nhap(){

    cout << "Nhap Ho Ten: "; fflush(stdin); cin.getline(Hoten,30);

    cout << "Nhap Ngay Sinh: "; fflush(stdin); cin.getline(NgaySinh,15);

    cout << "Nhap Que Quan: "; fflush(stdin); cin.getline(QueQuan,30);

}
void NGUOI::xuat(){

    cout << left << setw(30) << Hoten << left << setw(15) << NgaySinh
     << left << setw(30) <<QueQuan << endl;
}


class  SINHVIEN: public  NGUOI{

    char MaSV[15];
    char Nganh[10];
    int KhoaHoc;
public:
    void nhap();
    void xuat();
    friend void find_student_11(LOPHOC A);
    friend void sort_student(LOPHOC A);
    friend class LOPHOC;
};
void SINHVIEN::nhap(){
    NGUOI::nhap();
    cout << "Nhap Ma Sinh vien: "; fflush(stdin); cin.getline(MaSV,15);
    cout << "Nhap Nganh Sinh vien: "; fflush(stdin); cin.getline(Nganh,10);
    cout << "Nhap Khoa Hoc: "; cin >> KhoaHoc ;
}
void SINHVIEN::xuat(){


    cout << left << setw(15) << MaSV<< left << setw(10) << Nganh
    << left << setw(10) << KhoaHoc ;
    NGUOI::xuat();
}

class LOPHOC{
    char MaLH[10];
    char TenLH[10];
    char NgayMo[15];
    SINHVIEN *x;
    int n;
    char GIAOVIEN[30];
public:
    void nhap();
    void xuat();
    friend void find_student_11(LOPHOC A);
    friend void sort_student(LOPHOC A);
};
void LOPHOC::nhap(){
    cout << "Ma Lop Hoc: "; fflush(stdin); cin.getline(MaLH,10);
    cout << "Ten Lop Hoc: "; fflush(stdin); cin.getline(TenLH,10);
    cout << "Ngay Mo Lop Hoc: "; fflush(stdin); cin.getline(NgayMo,15);
    cout << "Nhap So Luong Hoc Sinh: ";
    cin >> n;
    x = new SINHVIEN[n];

    for(int i = 0;i<n;i++){
        x[i].SINHVIEN::nhap();
    }
    cout << "Nhap Ten Giao Vien: "; fflush(stdin);
    cin.getline(GIAOVIEN,30);
}
void LOPHOC::xuat(){
    cout << "Ma LOP: " << MaLH << " \t\t" << "Ten Lop: " << TenLH << " \t\tNgay mo: " << NgayMo << endl;
    cout << "Giao Vien Chu Nhiem: " << GIAOVIEN  << endl;
    cout << "Cac Sinh Vien: \n" ;

    cout << left << setw(15) << "Ma Sinh Vien" << left << setw(10) << "Nganh Hoc"
    << left << setw(10) << "Khoa Hoc" << left << setw(30) << "Ho va Ten"
    << left << setw(15) << "Ngay Sinh" << left << setw(30) << "Que Quan" << endl;
    for(int i = 0;i<n;i++){
        x[i].SINHVIEN::xuat();
    }
}

void find_student_11(LOPHOC A){

    int dem = 0;
    for(int i= 0;i<A.n;i++){

        if(A.x[i].KhoaHoc == 11) dem++;
    }
    cout << "Co " << dem << " sinh vien khoa 11" << endl;
}
void sort_student(LOPHOC A){

    for(int i = 0;i<A.n;i++){
        for(int j = 0;j<i;j++){
            if(A.x[i].KhoaHoc < A.x[j].KhoaHoc){
                swap(A.x[i],A.x[j]);
            }
        }
    }
}
int main()
{


        LOPHOC A;
        A.nhap();
        A.xuat();
        find_student_11(A);
        sort_student(A);
        A.xuat();

}
