#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <tr1/unordered_set>
#include <vector>
#define mp make_pair
#define pb push_back
#define MAX 220

using namespace std;
using namespace tr1;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef unsigned long long int64;

int n, b, x;

const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n >> b && n + b) {
        int maior = -1;
        vi globo;
        unordered_set<int> ball;
        for (int i = 0; i < b; ++i) {
            cin >> x;
            globo.pb(x);
            maior = max(maior, x);
        }
        for (int i = 0; i < globo.size(); i++)
            for (int j = i; j < globo.size(); j++)
                ball.insert(abs(globo[i] - globo[j]));
        if (ball.size() == n + 1)
            cout << "Y\n";
        else
            cout << "N\n";
    }
    return 0;
}
