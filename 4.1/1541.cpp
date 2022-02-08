#include <cstdio>
#include <iostream>

using namespace std;

const int N = 351;
const int M = 41;

int n, m;
int a[N], b[5];
int f[N][M][M][M];

inline void update(int &res, int val) {
    if (res < val)
        res = val;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int t, i = 1; i <= m; i++) cin >> t, b[t]++;
    f[1][0][0][0] = a[1];
    for (int i = 2; i <= n; i++)
    for (int j = 0; j <= b[1]; j++)
    for (int k = 0; k <= b[2]; k++)
    for (int l = 0; l <= b[3]; l++) {
        int g = i - j - 2 * k - 3 * l - 1;
        if (g < 0) break;
        if (g % 4 || g / 4 > b[4]) continue;
        if (j) update(f[i][j][k][l], f[i - 1][j - 1][k][l]);
        if (k) update(f[i][j][k][l], f[i - 2][j][k - 1][l]);
        if (l) update(f[i][j][k][l], f[i - 3][j][k][l - 1]);
        if (g) update(f[i][j][k][l], f[i - 4][j][k][l]);
        f[i][j][k][l] += a[i];
    }
    cout << f[n][b[1]][b[2]][b[3]] << endl;
    return 0;
}