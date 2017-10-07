#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#define mp make_pair

using namespace std;

int v, a;

typedef pair<int, int> ii;
typedef vector<ii> vii;
int visitado[10000];

int main(){
    ios::sync_with_stdio(false);
    int n, p;
    cin >> n;
    vector< vii > grafo;
    while ( n-- ){
		cin >> v >> a;
		grafo.resize(v+1);
		vii::iterator ia, ib;
		vii va, vb;
		int b, c;
		memset(visitado, 0, sizeof(visitado));
		for ( int i = 0; i < a; ++i ){
			cin >> b >> c >> p;
			grafo[b].push_back( mp(c, p));
			grafo[c].push_back( mp(b, p));
		}
		int num = a;
		for ( int i = 1; i <= v; ++i ){
			if ( grafo[i].size() == 2 ){
				int j = 0;
				va = grafo[i];
				int a = va[j].first, p1 = va[j].second; j++;
				int b = va[j].first, p2 = va[j].second;
				grafo[i].clear();
				ib = grafo[a].begin();
				while ( ib->first != i ) ib++;
				grafo[a].erase(ib+0);
				ib = grafo[b].begin();
				while ( ib->first != i ) ib++;
				grafo[b].erase(ib+0);
				grafo[a].push_back( mp(b, p1+p2) );
				grafo[b].push_back( mp(a, p1+p2) );
				num--;
			}
		}
		cout << num << "\n";
		for ( int i = 1; i <= v; ++i )
			sort(grafo[i].begin(), grafo[i].end());
		ii ant = mp(0, 0);
		for ( int i = 1; i <= v; ++i ){
			for ( ia = grafo[i].begin(); ia != grafo[i].end(); ia++ ){
				if ( !visitado[ia->first] ){
					if ( ant.first == ia->first && ant.second == ia->second ) continue;
					else cout << i << " " << ia->first << " " << ia->second << "\n";
					ant = mp(ia->first, ia->second);
				}
			}
			visitado[i] = 1;
			grafo[i].clear();
		}
		if ( n > 0 ) cout << "\n";
    }
    return 0;
}
