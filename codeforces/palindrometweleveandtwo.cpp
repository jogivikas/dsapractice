#include <iostream>
using namespace std;

bool isPalindrome(int n)
{
    int temp = n;
    int rev = 0;

    while (n > 0)
    {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    }

    return rev == temp;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int a, b;
        bool found = false;

        for (int i = 0; i <= n; i++)
        {
            if (isPalindrome(i) && (n - i) % 12 == 0)
            {
                a = i;
                b = n - i;

                cout << a << " " << b << endl;

                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << -1 << endl;
        }
    }

    return 0;
}