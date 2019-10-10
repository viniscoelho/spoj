#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int p;
    bool flag = false;
    while (cin >> p) {
        if (p == 42)
            flag = true;
        if (!flag)
            cout << p << endl;
    }
    return 0;
}