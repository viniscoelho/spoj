#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long uint64;
typedef unsigned long long int64;

struct tri {
    int ini, opa, idx;
    int tipo;
    tri(int tipo = 0, int ini = 0, int opa = 0, int idx = 0)
        : tipo(tipo)
        , ini(ini)
        , opa(opa)
        , idx(idx)
    {
    }
    bool operator<(const tri& at) const
    {
        if (ini != at.ini)
            return ini < at.ini;
        if (tipo != at.tipo)
            return tipo < at.tipo;
        return idx < at.idx;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    int t, n, a, b;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<tri> eventos;
        set<int> livre;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            eventos.push_back(tri(0, a, a, i));
            eventos.push_back(tri(1, b, a, i));
        }
        sort(eventos.begin(), eventos.end());
        set<int> at;
        for (int i = 0; i < 2 * n; i++) {
            if (eventos[i].tipo) {
                at.erase(eventos[i].opa);
            } else {
                at.insert(eventos[i].ini);
                ans = max(ans, (int)at.size());
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
