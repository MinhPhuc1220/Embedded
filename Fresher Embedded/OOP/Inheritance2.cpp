#include <bits/stdc++.h>
using namespace std;

/*
Thứ tự khởi tạo Constructor : Base Class -> Drived Class
Thứ tự khởi tạo Destructor : Drived Class -> Base Class

Multilevel Inheritance (kế thừa nhiều mức): C con B, B con A (mức độ ưu tiên hàm C -> B -> A)
Multiple Inheritance (đa kế thừa -> kế thừa từ nhiều lớp): E con A và D
Hierarchical Inheritance (kế thừa phân cấp): B,C,D,E đều là con A
*/

// Multilevel Inheritance: C con B, B con A
class A{
    public:
        //Base Constructor
        A(){
            cout << "Constructor lop A\n";
        }
        //Base Destructor
        ~A(){
            cout << "Destructor lop A\n";
        }
        void xinchao(){
            cout << "Xin chao A!\n";
        }
};

class B : public A{
    public:
        //Drived Constructor
        B(){
            cout << "Constructor lop B\n";
        }
        //Drived Destructor
        ~B(){
            cout << "Destructor lop B\n";
        }
        void xinchao(){
            cout << "Xin chao B!\n";
        }
};

class C : public B{
    public:
        //Drived Constructor
        C(){
            cout << "Constructor lop C\n";
        }
        //Drived Destructor
        ~C(){
            cout << "Destructor lop C\n";
        }
        void xinchao(){
            cout << "Xin chao C!\n";
        }
};


//Multiple Inheritance: E con A và D
class D{
    public:
        D(){
            cout << "Constructor lop D\n";
        }
        ~D(){
            cout << "Destructor lop D\n";
        }
        void xinchao(){
            cout << "Xin chao D!\n";
        }
};

class E : public A, public D{
    public:
        E(){
            cout << "Constructor lop E\n";
        }
        ~E(){
            cout << "Destructor lop E\n";
        }
};
int main(int argc, char const *argv[])
{
    // Multilevel Inheritance: C con B, B con A
    // C obj;
    // obj.xinchao();

    //Multiple Inheritance: E con A và D
    E obj;
    obj.D::xinchao(); // phải chỉ rõ ra phạm vi hàm 
    return 0;
}
