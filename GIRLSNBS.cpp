#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int g, b;
    for ( cin >> g >> b; g != -1 && b != -1; cin >> g >> b ){
		float MAX = max( g, b ), MIN = min( g, b )+1;
        float resp = (MAX/MIN);
        cout << ceil(resp) << "\n";
    }
    return 0;
}
