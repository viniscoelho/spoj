#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define MAXN 110000
#define mp make_pair

using namespace std;

struct segment {
    int a, b, c;

    segment(int a = 0, int b = 0, int c = 0)
        : a(a)
        , b(b)
        , c(c)
    {
    }

    segment operator+(segment s)
    {
        return segment(a + s.a, b + s.b, c + s.c);
    }

    void swap()
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;

        a = a ^ c;
        c = a ^ c;
        a = a ^ c;
    }
};

segment tree[5 * MAXN];
int lazy[5 * MAXN];

int readInt()
{
    bool minus = false;
    int result = 0;
    char ch = getchar_unlocked();
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

void build(int node, int tl, int tr)
{
    if (tl == tr) // leaf
    {
        tree[node] = segment(1, 0, 0);
    } else {
        int tm = (tl + tr) >> 1;
        build(2 * node, tl, tm);
        build(2 * node + 1, tm + 1, tr);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

void lazy_propagate(int node)
{
    lazy[node] %= 3;
    for (int i = 0; i < lazy[node]; i++)
        tree[node].swap();

    lazy[2 * node] += lazy[node];
    lazy[2 * node + 1] += lazy[node];
    lazy[node] = 0;
}

segment propagated_node(int node)
{
    if (lazy[node])
        lazy_propagate(node);
    return tree[node];
}

int query(int node, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (tl >= l && tr <= r) {
        if (lazy[node])
            lazy_propagate(node);
        return tree[node].a;
    } else {
        //if this node is not propagated yet, propagate it
        if (lazy[node])
            lazy_propagate(node);

        int tm = (tl + tr) >> 1;
        return query(2 * node, tl, tm, l, min(tm, r)) + query(2 * node + 1, tm + 1, tr, max(l, tm + 1), r);
    }
}

void update(int node, int tl, int tr, int i, int j, int value)
{
    // current segment is not within range [i, j]
    if (tl > tr || tl > j || tr < i)
        return;

    if (tl >= i && tr <= j) {
        lazy[node] += value;
        return;
    } else // not a leaf node
    {
        int tm = (tl + tr) >> 1;
        update(2 * node, tl, tm, i, j, value); // updating left child
        update(2 * node + 1, tm + 1, tr, i, j, value); // updating right child
        //inner node will receive values from propagated children
        tree[node] = propagated_node(2 * node) + propagated_node(2 * node + 1);
    }
}

int main()
{
    int n, m, a, b, opc;
    n = readInt();
    build(1, 0, n - 1);
    m = readInt();
    //no need to initialize lazy, since it is just one test case at once
    for (int i = 0; i < m; i++) {
        opc = readInt();
        a = readInt();
        b = readInt();
        if (opc) {
            int resp = query(1, 0, n - 1, a, b);
            printf("%d\n", resp);
        } else {
            update(1, 0, n - 1, a, b, 1);
        }
    }
    return 0;
}
