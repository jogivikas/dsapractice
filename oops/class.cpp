#include <bits/stdc++.h>
using namespace std;

class Teacher
{
private:
    int salary;

public:
    string name;
    string dept;

    // setter
    void setSalary(int s)
    {
        salary = s;
    }

    // getter
    int getSalary()
    {
        return salary;
    }
    Teacher() // non perametrazied contructor
    {
        dept = "csit";
    }
    // parametarized contructor
    Teacher(string n)

    {
        name = n;
    }
    // copy contructor
    Teacher(Teacher &orgobj)
    {
        cout << "copy contructor";
        this->name = orgobj.name;
    }
};

int main()
{
    Teacher t("vikas"); // time of creation object the constructor automatically call
    // t.name = "vikas";

    // t.setSalary(500);

    // // cout << t.salary << endl; ❌ not allowed
    // cout << t.dept << endl;
    cout << t.name << endl;
    Teacher t2(t);

    // cout << t.dept << endl;
    // cout << t.getSalary() << endl;

    return 0;
}