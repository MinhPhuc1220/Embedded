#include <bits/stdc++.h>
using namespace std;

/* 
Operator Overloading 
cout <<: class ostream
cin >>: class istream
Hàm so sánh nạp chồng toán tử theo 2 cách:
- Xây dựng theo Friend Function (cần 2 tham số truyền vào để thực hiện so sánh)
- Xây dựng operator là member của class (chỉ cần 1 tham số truyền vào)
=> Nạp chồng nhập xuất (cin cout) bắt buộc sd friend function
*/

class SinhVien{
    private:
        string id, name, birth;
        double gpa;
    public:
        //Constructor
        SinhVien(); 
        //Hàm nhập xuất thông tin sd nạp chồng toán tử
        friend istream& operator >> (istream &in, SinhVien &a);
        friend ostream& operator << (ostream &out, SinhVien a);
        //Hàm so sánh nạp chồng toán tử theo 2 cách
        friend bool operator < (SinhVien a, SinhVien b);
        bool operator > (SinhVien a);
};

// Nạp chồng toán tử << >>
istream& operator >> (istream &in, SinhVien &a){
    cout << "Nhap id :";
    cin >> a.id;
    cout << "Nhap ten:";
    in.ignore();
    getline(in, a.name);
    cout << "Nhap ngay sinh:";
    in >> a.birth;
    cout << "Nhap diem:";
    in >> a.gpa;
    return in;
}

ostream& operator << (ostream &out, SinhVien a){
    cout << a.id << " " << a.name << " " << a.birth << " " << fixed << setprecision(2) << a.gpa << endl;
    return out;
}

// Nạp chồng toán tử cách 1
bool operator < (SinhVien a, SinhVien b){
    return a.gpa < b.gpa;
}

// Nạp chồng toán tử cách 2
bool SinhVien::operator > (SinhVien a){
    return this->gpa > a.gpa;
}


SinhVien::SinhVien(){
    this->id = "18151223";
    this->name = this->birth = "";
    this->gpa = 0;
}

int main(int argc, char const *argv[])
{
    SinhVien A, B;
    cin >> A >> B;

    if (A < B)
    {       
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    
    // cout << A;
    return 0;
}
