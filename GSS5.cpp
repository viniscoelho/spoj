//#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define mp make_pair
#define pb push_back
#define MAXN 51000

using namespace std;

typedef long long int64;

int m, n;

struct data {
    int64 sum, pref, suff, ans;
    data(int64 sum = 0, int64 pref = 0, int64 suff = 0, int64 ans = 0)
        : sum(sum)
        , pref(pref)
        , suff(suff)
        , ans(ans)
    {
    }
};

data t[5 * MAXN];
int a[MAXN];

int readInt()
{
    bool minus = false;
    int result = 0;
    char ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9')
            break;
        ch = getchar_unlocked();
    }
    if (ch == '-')
        minus = true;
    else
        result = ch - '0';
    while (true) {
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9')
            break;
        result = result * 10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

data combine(data l, data r)
{
    data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}

data make_data(int64 val)
{
    return data(val, val, val, val);
}

void build(int node, int tl, int tr)
{
    if (tl == tr)
        t[node] = make_data(a[tl]);
    else {
        int tm = (tl + tr) >> 1;
        build(2 * node, tl, tm);
        build(2 * node + 1, tm + 1, tr);
        t[node] = combine(t[2 * node], t[2 * node + 1]);
    }
}

void update(int node, int tl, int tr, int pos, int64 new_val)
{
    if (tl == tr)
        t[node] = make_data(new_val);
    else {
        int tm = (tl + tr) >> 1;
        if (pos <= tm)
            update(2 * node, tl, tm, pos, new_val);
        else
            update(2 * node + 1, tm + 1, tr, pos, new_val);
        t[node] = combine(t[2 * node], t[2 * node + 1]);
    }
}

data query(int node, int tl, int tr, int l, int r)
{
    if (l > r || l < 0 || r < 0 || r > tr || l < tl)
        return make_data(0);
    if (l == tl && tr == r)
        return t[node];
    int tm = (tl + tr) >> 1;
    if (r <= tm)
        return query(2 * node, tl, tm, l, r);
    if (l > tm)
        return query(2 * node + 1, tm + 1, tr, l, r);
    return combine(query(2 * node, tl, tm, l, tm), query(2 * node + 1, tm + 1, tr, tm + 1, r));
}

int main()
{
    int t;
    t = readInt();
    while (t--) {
        n = readInt();
        int opc, x1, y1, x2, y2;
        for (int i = 0; i < n; i++) {
            a[i] = readInt();
        }
        build(1, 0, n - 1);

        m = readInt();
        data resp;
        while (m--) {
            x1 = readInt();
            y1 = readInt();

            x2 = readInt();
            y2 = readInt();

            data suf, sum, pref;
            int64 ans = 0;

            if (x1 == y1 && y1 == x2) {
                sum = query(1, 0, n - 1, x1 - 1, y1 - 1); //miolo
                ans = sum.sum;
                if (x2 != y2) {
                    pref = query(1, 0, n - 1, x2, y2 - 1); //pref
                    ans += pref.pref;
                }
            } else if (y1 >= x2) {
                //compartilham um subconjunto
                suf = query(1, 0, n - 1, x1 - 1, x2 - 2); //suf
                sum = query(1, 0, n - 1, x2 - 1, y1 - 1); //miolo
                pref = query(1, 0, n - 1, y1, y2 - 1); //pref
                ans = max(suf.suff + sum.sum + pref.pref, suf.suff + sum.sum);
                ans = max(ans, max(sum.sum + pref.pref, suf.sum + sum.sum));
                ans = max(ans, max(suf.sum + sum.sum + pref.pref, suf.sum + sum.sum + pref.sum));
                ans = max(ans, max(suf.suff + sum.sum + pref.sum, sum.sum + pref.sum));
            } else {
                //disjuntos
                suf = query(1, 0, n - 1, x1 - 1, y1 - 1); //suf
                if (x2 - y1 > 1)
                    sum = query(1, 0, n - 1, y1, x2 - 2); //miolo
                else
                    sum = make_data(0);
                pref = query(1, 0, n - 1, x2 - 1, y2 - 1); //pref
                ans = suf.suff + sum.sum + pref.pref;
            }

            printf("%lld\n", ans);
        }
    }
    return 0;
}
