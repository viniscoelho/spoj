#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <queue>
#include <map>
#include <cstdlib>
#define mp make_pair
#define pb push_back
#define MAXV 200010

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long int64;

int64 posicao[MAXV];

void create(vector<int>& v, int n)
{
    v.assign(n + 1, 0);
}

int rsq(vector<int>& v, int a, int b) {
    if (a == 0) {
        int sum = 0;
        for (; b >= 0; b = (b & (b + 1)) - 1){
            sum += v[b];
        }
        return sum;
    } else {
        return rsq(v, 0, b) - rsq(v, 0, a-1);
    }
}

void adjust(vector<int>& t, int k, int value)
{
    for (; k <= t.size(); k |= k + 1){
        t[k] += value;
    }
}

int main(){
	ios::sync_with_stdio(false);
	int m, n;
	cin >> m;
	while ( m-- ){
		int64 a, sum = 0;
		cin >> n;
        vector<int> ft;
        create(ft, n+1);
        map<int64, int> numeros;
		for ( int i = 0; i < n; i++ ){
			cin >> posicao[i];
            numeros.insert(mp(posicao[i], 0));
		}
        
        map<int64, int>::iterator it;
        int k = 0;
        for ( it = numeros.begin(); it != numeros.end(); it++ )
            it->second = k++;
        
        for ( int i = 0; i < n; ++i )
        {
            int resp = numeros[posicao[i]];
            adjust(ft, resp, 1);
            //count how many guys were added in that range
            sum += abs(rsq(ft, 0, resp)-rsq(ft, 0, n));
        }
		cout << sum << "\n";
	}
}