#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> ii;

typedef long long int64;

int64 __lcm(int64 a, int64 b){ return (a * (b / __gcd(a, b))); }

int pos[6], memo[6];
int64 n, m;

int64 solve(int at, int mask)
{
    if ( mask == 32 ) return memo[at];
    int b = __builtin_popcount(mask);
    if ( b == at )
    {
        int64 l = 1;
        for ( int i = 0; i < 5; i++ )
        {
            if ( mask & (1 << i) ) l = __lcm(l, pos[i]);
        }
        memo[at] += (m/l - n/l);
    }
    return solve(at, mask+1);
}


int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int64 a, d;
    while ( t-- ){
        for ( int i = 0; i < 6; i++ ) memo[i] = 0;
        cin >> n >> m >> a >> d;
        n--;
        pos[0] = a;
        pos[1] = a+d;
        pos[2] = a+2*d;
        pos[3] = a+3*d;
        pos[4] = a+4*d;

        int64 ans = 0;

        for ( int i = 0; i < 5; i++ )
            ans += (m/pos[i] - n/pos[i]);

        for ( int i = 1; i <= 4; i++ )
        {
            if ( i & 1 ) ans -= solve(i+1, 3);
            else ans += solve(i+1, 3);
        }

        cout << (m-n)-ans << endl;

    }
    return 0;
}
