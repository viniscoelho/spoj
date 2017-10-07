#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back

using namespace std;

int neigh[100010];

typedef pair<int, int> ii;
typedef long long int64;

int main()
{
	ios::sync_with_stdio(false);
	int c, n;
	while ( cin >> c >> n && c + n )
	{
		for ( int i = 0; i < n; i++ )
		{
			cin >> neigh[i];
		}
		map<int, int> vizinhos;
		vizinhos.insert(mp(0, 0));
		int ans = 0;
		bool flag = false;
		for ( int i = 0; i < n; i++ )
		{
			ans = (ans + neigh[i]) % c;
			if ( !vizinhos.count(ans) ) vizinhos.insert(mp(ans, i+1));
			else
			{
				flag = true;
				for ( int k = vizinhos[ans]+1; k <= i+1; k++ )
				{
					cout << ((k == vizinhos[ans]+1) ? "" : " ");
					cout << k;
				}
				cout << endl;
				break;
			}
		}
		if ( !flag ) cout << "no sweets\n";
	}
	return 0;
}