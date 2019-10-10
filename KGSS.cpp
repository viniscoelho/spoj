#include <bits/stdc++.h>
#define MAXN 100010
#define mp make_pair

using namespace std;

typedef pair<int, int> segment;

int n;
segment tree[4 * MAXN];
int elem[MAXN];

/* get highest and second highest values */
segment merge(segment l, segment h)
{
    int vet[] = { l.first, l.second, h.first, h.second };
    sort(vet, vet + 4);
    return mp(vet[3], vet[2]);
}

void build(int node, int tl, int tr)
{
    if (tl == tr)
        tree[node] = mp(elem[tl], 0);
    else {
        int tm = (tl + tr) / 2;
        build(2 * node, tl, tm);
        build(2 * node + 1, tm + 1, tr);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
}

/* get the sum of the interval
int sum (int node, int tl, int tr, int left, int right)
{
    if (left > right) return 0;
    if (left == tl && right == tr) return tree[node];
    int tm = (tl + tr) / 2;
    return sum (2*node, tl, tm, left, min(right, tm)) +
        sum (2*node+1, tm+1, tr, max(left, tm+1), right);
}
*/

segment query(int node, int tl, int tr, int left, int right)
{
    if (left > right)
        return mp(0, 0);
    if (left == tl && right == tr)
        return tree[node];
    int tm = (tl + tr) / 2;

    return merge(query(2 * node, tl, tm, left, min(right, tm)),
        query(2 * node + 1, tm + 1, tr, max(left, tm + 1), right));
}

void update(int node, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
        tree[node].first = new_val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * node, tl, tm, pos, new_val);
        else
            update(2 * node + 1, tm + 1, tr, pos, new_val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
}

int main()
{
    int n, m, a, b;
    char opc;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &elem[i]);
    build(1, 0, n - 1);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf(" %c %d %d", &opc, &a, &b);
        if (opc == 'Q') {
            segment resp = query(1, 0, n - 1, a - 1, b - 1);
            printf("%d\n", resp.first + resp.second);
        } else {
            update(1, 0, n - 1, a - 1, b);
        }
    }
    return 0;
}
