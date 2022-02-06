#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int S = 101;
const int N = 101;
const int M = 20001;

int s, n, m;
int enemy[N][S], f[2][M];

int main() {
    ios::sync_with_stdio(false);
    cin >> s >> n >> m;
    for (int i = 1; i <= s; i++)
    for (int j = 1; j <= n; j++)
        cin >> enemy[j][i], enemy[j][i] <<= 1;
    for (int i = 1; i <= n; i++)
        sort(enemy[i] + 1, enemy[i] + s + 1);
    int now = 0, last = 1;
    for (int i = 1; i <= n; i++) {
        swap(now, last), memset(f[now], 0, sizeof(f[now]));
        for (int j = 1; j <= s; j++)
        for (int k = m; k > enemy[i][j]; k--)
            f[now][k] = max(f[now][k], f[last][k - (enemy[i][j] + 1)] + i * j);
        for (int k = m; k >= 0; k--)
            f[now][k] = max(f[now][k], f[last][k]);
    }
    cout << f[now][m] << endl;
    return 0;
}