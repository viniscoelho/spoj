#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> ii;

typedef long long int64;

int64 __lcm(int64 a, int64 b) { return (a * (b / __gcd(a, b))); }

int64 pos[16], memo[32678];
int64 n, k;

int64 solve(int at, int mask)
{
    if (mask == (1 << k))
        return memo[at];
    int b = __builtin_popcount(mask);
    if (b == at) {
        int64 l = 1;
        for (int i = 0; i < k; i++) {
            if (mask & (1 << i))
                l = __lcm(l, pos[i]);
        }
        memo[at] += n / l;
    }
    return solve(at, mask + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    int64 a, d;
    cin >> n >> k;

    int64 ans = 0;
    for (int i = 0; i < k; i++) {
        cin >> pos[i];
        ans += n / pos[i];
    }

    for (int i = 1; i < k; i++) {
        if (i & 1)
            ans -= solve(i + 1, 3);
        else
            ans += solve(i + 1, 3);
    }

    cout << n - ans << endl;
    return 0;
}
