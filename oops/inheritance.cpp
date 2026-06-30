
#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name;
    string age;

    Person(string name, string age)
    {
        this->name = name;
        this->age = age;
    }
    // Person()
    // {
    //     cout << "hi im a constructor of class Person" << endl;
    // }
};
class Student : public Person
{

public:
    string art;

    // Student()
    // {
    //     cout << "student contri=cuot" << endl;
    // }
    Student(string name, string age, string art) : Person(name, age)
    {
        this->art = art;
    }

    void getinfo()
    {
        cout << "name" << name << endl;
        cout << "age" << age << endl;
        cout << "art" << art << endl;
    }
};

int main()
{
    Student s("vikas", "44", "gdg");

    s.getinfo();
    return 0;
}