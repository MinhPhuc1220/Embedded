#include <bits/stdc++.h>
using namespace std;

/*
Mặc dù lớp con kế thừa từ lớp cha, lớp con sẽ có đầy đủ attitube và method của lớp cha nhưng không phải lúc nào cũng truy cập vào được (còn tùy thuộc vào access mode và access modifier)
base class: class cha
drived class: class con
Quan hệ is-a: "drived class is-a base class"
"Access mode": public (access modifier trong drived class sẽ giống với base class), private (tất cả member ở base class sẽ thành private trong drived class), protected (member public ở base class sẽ thành protected ở derived class)
Function overriding: ưu tiên gọi hàm ở drived class
Drived Constructor: constructor trong drived class (lưu ý cách khởi tạo)
Tính chất OOP:
- Encapsulation (đóng gói)
- Inheritance (kế thừa)
*/

class Person{
    private:
        string name, address;
    public:
        //Base Constructor
        Person(string name, string address){
            this->name = name;
            this->address = address;
        }
        string getName(){
            return name;
        }
        void setName(string name){
            this->name = name;
        }
        string getAddress(){
            return address;
        }
        void setAddress(string address){
            this->address = address;
        }
        void nhapThongTin(){
            cout << "Nhap ten:";
            getline(cin,this->name);
            cout << "Nhap dia chi:";
            getline(cin,this->address);
        }
        void inThongTin(){
            cout << this->name << " " << this->address << " ";
        }
};

class Student : public Person{
    private:
        float gpa;
    public:
        //Drived Constructor
        Student(string name, string address, float gpa) : Person(name, address){
            this->gpa = gpa;
        }
        float getGpa(){
            return gpa;
        }
        void setGpa(float gpa){
            this->gpa = gpa;
        }

        // Function overriding
        void nhapThongTin(){
            Person::nhapThongTin();
            cin >> this->gpa;
        }
        void inThongTin(){
            //cach 1
            // cout << getName() << " " << getAddress() << " " << fixed << setprecision(2) << this->gpa << endl;
            //cach 2
            Person::inThongTin();
            cout << this->gpa << endl;
        }
};


class Lecturer : public Person{


};

int main(int argc, char const *argv[])
{
    Student A("Tran Minh Phuc", "Hue", 4.0);
    // A.setName("Tran Minh Phuc");
    // A.setAddress("Hue");
    // A.setGpa(4.0);
    

    // A.nhapThongTin();
    A.inThongTin();
    // gọi ở base class
    // A.Person::nhapThongTin();
    // A.Person::inThongTin();


    return 0;
}
