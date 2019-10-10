#include <iostream>

using namespace std;

int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    int r, c;
    char str[100];
    while (cin >> r >> c && r && c) {
        int mat[100][100], aux[100][100];
        ;
        for (int i = 0; i < r; i++) {
            cin >> str;
            for (int j = 0; j < c; j++) {
                if (str[j] == 'X')
                    mat[i][j] = aux[i][j] = 1;
                else
                    mat[i][j] = aux[i][j] = 0;
            }
        }
        int resp = INF;
        for (int i = 0; i < (1 << c); i++) {
            int click = 0;
            for (int j = 0; j < c; j++) {
                if (i & (1 << j)) {
                    if (j - 1 >= 0)
                        mat[0][j - 1] = !mat[0][j - 1];
                    if (j + 1 < c)
                        mat[0][j + 1] = !mat[0][j + 1];
                    if (r >= 2)
                        mat[1][j] = !mat[1][j];
                    mat[0][j] = !mat[0][j];
                    click++;
                }
            }
            bool flag = false;
            if (r >= 2) {
                for (int j = 1; j < r; j++) {
                    for (int k = 0; k < c; k++) {
                        if (mat[j - 1][k]) {
                            if (k - 1 >= 0)
                                mat[j][k - 1] = !mat[j][k - 1];
                            if (k + 1 < c)
                                mat[j][k + 1] = !mat[j][k + 1];
                            if (j + 1 < r)
                                mat[j + 1][k] = !mat[j + 1][k];
                            mat[j - 1][k] = !mat[j - 1][k];
                            mat[j][k] = !mat[j][k];
                            click++;
                        }
                        mat[j - 1][k] = aux[j - 1][k];
                    }
                }
            }
            for (int j = 0; j < c; j++) {
                if (mat[r - 1][j])
                    flag = true;
                mat[r - 1][j] = aux[r - 1][j];
            }
            if (!flag)
                resp = min(click, resp);
        }
        if (resp != INF)
            cout << "You have to tap " << resp << " tiles.\n";
        else
            cout << "Damaged billboard.\n";
    }
    return 0;
}
