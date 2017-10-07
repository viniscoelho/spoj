#include <stdio.h>

int main(){
	int i, j, n, aux = 0;
	while ( scanf("%d", &n) && n ){
		int aux = 0;
		for ( i = 1; i <= n; i++ ) aux += (i*i);
		printf("%d\n", aux);
	}
	return 0;
}
