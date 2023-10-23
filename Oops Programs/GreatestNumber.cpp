// In this program we gonna find the greated number entered in respective class using friend class.

#include<iostream>
#include<conio.h>

using namespace std;

class a;

class b{
    int number;
    public:
    b(int x){
        number = x;
    }
    void friend greatest(a a1, b b1);
};

class a{
    int number;
    public:
    a(int x){
        number = x;
    }
    void friend greatest(a a1, b b1);
};

void greatest (a a1 , b b1){
    if (a1.number>b1.number){
        cout << "\n Number in class A is greatest - " << a1.number;
    }
    else if(a1.number<b1.number){
        cout << "\n Number in class B is Greatest - " << b1.number; 
    }
    else {
        cout << "\n Number in both the classes are equal - ";
    }
}

int main(){
    int num;
    cout << "\n \n Enter the Number For class A - ";
    cin >> num;
    a a1(num);

    cout << "\n Enter the Number for class B - ";
    cin >> num;
    b b1(num);

    greatest (a1 , b1);
    cout << "\n";
    getch();
    return 0;
}