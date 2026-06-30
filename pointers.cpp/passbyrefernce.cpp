#include <bits/stdc++.h>
using namespace std;

void print(int *ptr)
{
    *ptr = 56;
}

int main()
{

    int a = 10;

    print(&a);

    cout << a;

    return 0;
}