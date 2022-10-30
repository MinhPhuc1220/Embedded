#include <bits/stdc++.h>
using namespace std;

/*
Class (lớp) gồm attribute (thuộc tính) và method (phương thức) 
Object (đối tượng) là thực thể của Class
:: là toán tử phạm vi (scope) (dùng để khởi tạo attribute hoặc method trong class)
Accept modifier (phạm vi truy cập): private (chỉ truy cập trong class, thường sd cho attribute), public (có thể truy cập bên trong hoặc ngoài class, thường sd cho method), protected
Constructor: Hàm khởi tạo - luôn được tạo khi khai báo obj (cùng tên với Class và không có kiểu trả về) => có thể gán tham số vào constructor (nạp chồng constructor)
Destructor: Hàm hủy - được gọi khi obj kết thúc ({}, kết thúc ct, kết thúc hàm gọi obj đó) (cùng tên với Class và không có kiểu trả về, ~)
This pointer: chỉ attribute đang thao tác thuộc Class
Setter: lấy attribute để thực hiện công việc gì đấy
Getter: chỉnh sửa attribute
Phép gán Object (=): gán từng attribute cho nhau
Overloading (nạp chồng hàm), Overriding (ghi đè phương thức)
Tính chất OOP:
- Encapsulation (đóng gói)

*/
class SinhVien{
    private:
        string id, name, birth;
        double gpa;
    public:
        //Default Constructor
        SinhVien(); 
        //Parameterized Constructor (Hàm khởi tạo có tham số - nạp chồng constructor)
        SinhVien(string, string, string, double); 
        //Destructor
        ~SinhVien(); 
        //Getter, Setter
        double getGpa();
        string getId();
        string getName();
        string getBirth();
        void setGpa(double);
        //Hàm nhập xuất thông tin
        void NhapThongTin();
        void InThongTin();
};

// Implementation SinhVien
SinhVien::SinhVien(){
    cout << "Ham khoi tao duoc goi\n";
    this->id = this->name = this->birth = "";
    this->gpa = 0;
}

SinhVien::SinhVien(string id, string name, string birth, double gpa){
    cout << "Ham khoi tao co tham so duoc goi\n";
    this->id = id;
    this->name = name;
    this->birth = birth;
    this->gpa = gpa;
}

SinhVien::~SinhVien(){
    cout << "Obj duoc huy tai day\n";
}

void SinhVien::NhapThongTin(){
    cout << "Nhap MSSV:"; 
    cin >> this->id;
    cin.ignore();

    cout << "Nhap ten:";
    getline(cin,this->name); 

    cout << "Nhap ngay sinh:"; 
    cin >> this->birth;

    cout << "Nhap diem:"; 
    cin >> this->gpa;
}

void SinhVien::InThongTin(){
    cout << this->id << " " << this->name << " " << this->birth << " " << fixed << setprecision(2) << this->gpa << endl;
}

double SinhVien::getGpa(){
    return this->gpa; //return gpa;
}

void SinhVien::setGpa(double gpa){
    this->gpa = gpa; //return gpa;
}

int main(int argc, char const *argv[])
{
    SinhVien A;
    //SinhVien A("18151223", "Tran Minh Phuc", "01/02/2000", 4.0);
    A.NhapThongTin();
    A.InThongTin();
    return 0;
}
