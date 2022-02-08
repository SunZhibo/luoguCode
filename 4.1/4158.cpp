#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 51;
const int T = 2501;
const int inf = 1e9;

int n, m, t;
char str[N]; bool color[N];
int f[N][N][2], h[N], g[T];

inline void up(int &x, const int y) {
    if (x < y) x = y;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> t;
    while(n--) {
        cin >> str + 1;
        for (int i = 1; i <= m; i++)
            color[i] = str[i] - '0';
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
        for (int c = 0; c < 2; c++) {
            up(f[i][j][c], f[i - 1][j][c] + (color[i] == c));
            up(f[i][j][c], max(f[i - 1][j - 1][0], f[i - 1][j - 1][1]) + (color[i] == c));
        }
        for (int i = 1; i <= m; i++)
            h[i] = max(f[m][i][0], f[m][i][1]);
        for (int i = t; i >= 0; i--)
        for (int j = 1; j <= m; j++) {
            if (j > i) break;
            up(g[i], g[i - j] + h[j]);
        }
    }
    cout << g[t] << endl;
    return 0;
}
