#include <iostream>

using namespace std;
 
int pow ( int n, int e ){  
    long r = n;  
    for ( int i = 1; i < e; i++ ) r *= n;  
    return r;
}
     
int main(){
    ios::sync_with_stdio(false);
    int p;
    cin >> p;
    for ( int i = 0; i < p; ++i ){
        int con, nZeros = 0, loop = 1, count = -1;
        cin >> con;
        while ( count != 0 ){
			count = ( con / pow(5, loop) );
			nZeros += count;
			loop++;
        }
        cout << nZeros << endl;
    }
    return 0;
}  
