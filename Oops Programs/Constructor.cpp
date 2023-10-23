#include<iostream>
#include<conio.h>

using namespace std;

class student{
    int rollno;
    char name[50];
    double fee;
    public:
    student()
    {
        cout << "Enter the roll number";
        cin >> rollno;
        cout << "Enter the name";
        cin >> name;
        cout << "Enter the Fee";
        cin >> fee;
    }
    void display()
    {
        cout << endl << rollno << name << fee;
    }
};
int main()
{
    student s;
    s.display();
    return 0;
}