#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define MAXN 51000

using namespace std;

typedef long long int64;

int m, n;

struct data
{
    int64 sum, pref, suff, ans;
    data(int64 sum = 0, int64 pref = 0, int64 suff = 0, int64 ans = 0) : sum(sum), pref(pref), suff(suff), ans(ans) {}
};

data t[4*MAXN];
int a[MAXN];

int readInt ()
{
    bool minus = false;
    int result = 0;
    char ch = getchar_unlocked();
    while (true)
    {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar_unlocked();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true)
    {
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus) return -result;
    else return result;
}

data combine (data l, data r)
{
    data res;
    res.sum = l.sum + r.sum;
    res.pref = max (l.pref, l.sum + r.pref);
    res.suff = max (r.suff, r.sum + l.suff);
    res.ans = max (max (l.ans, r.ans), l.suff + r.pref);
    return res;
}

data make_data (int64 val)
{
    return data(val, val, val, val);
}

void build (int node, int tl, int tr)
{
    if (tl == tr)
        t[node] = make_data(a[tl]);
    else
    {
        int tm = (tl + tr) >> 1;
        build (2*node, tl, tm);
        build (2*node+1, tm+1, tr);
        t[node] = combine(t[2*node], t[2*node+1]);
    }
}
 
void update (int node, int tl, int tr, int pos, int64 new_val)
{
    if (tl == tr) t[node] = make_data(new_val);
    else
    {
        int tm = (tl + tr) >> 1;
        if (pos <= tm)
            update (2*node, tl, tm, pos, new_val);
        else
            update (2*node+1, tm+1, tr, pos, new_val);
        t[node] = combine (t[2*node], t[2*node+1]);
    }
}

data query (int node, int tl, int tr, int l, int r)
{
    if (l > r || l < 0 || r < 0 || r > tr || l < tl) return make_data(0);
    if (l == tl && tr == r) return t[node];
    int tm = (tl + tr) >> 1;
    if (r <= tm)
        return query (2*node, tl, tm, l, r);
    if (l > tm)
        return query (2*node+1, tm+1, tr, l, r);
    return combine(query (2*node, tl, tm, l, tm), query (2*node+1, tm+1, tr, tm+1, r)
    );
}

int main()
{
    n = readInt();
    int x, y;
    for ( int i = 0; i < n; i++ )
    {
        a[i] = readInt();
    }
    build(1, 0, n-1);
    m = readInt();
    while ( m-- )
    {
        x = readInt();
        y = readInt();
        data resp = query(1, 0, n-1, x-1, y-1);
        printf("%lld\n", resp.ans);
    }
    return 0;
}
