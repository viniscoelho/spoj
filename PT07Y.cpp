#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <list>
#include <vector>

using namespace std;

vector< list<int> > vli;

bool visitado[10010];
bool flag = false;

void runDFS( int u ){
	list<int>::iterator it;
	for ( it = vli[u].begin(); it != vli[u].end(); it++ ){
		if ( !visitado[*it] ){
			visitado[*it] = true;
            runDFS(*it );
		}
		else if ( visitado[*it] ){
				flag = true;
				return;
		}
	}
}

void DFS( int n ){
	for ( int i = 0; i < n; ++i )
		if ( !visitado[i] ){
			runDFS(i);
            if ( flag ){
				cout << "NO";
				return;
            }
		}
	cout << "YES";
}

int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vli.resize(n);
	for ( int i = 0; i < n; ++i ) visitado[i] = false;
	int a, b;
	for ( int i = 0; i < m; ++i ){
		cin >> a >> b;
		vli[a-1].push_back( b-1 );
	}
	DFS( n );
	return 0;
}
