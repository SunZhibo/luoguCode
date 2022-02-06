#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int M = 1001;
const int MOD = 1e8;

int n, mod;
int f[2][M];

int main() {
    ios::sync_with_stdio(false);
    int now = 0, last = 1;
    cin >> n >> mod, f[now][0] = 1;
    for (int t, i = 1; i <= n; i++) {
        cin >> t, swap(now, last);
        memset(f[now], 0, sizeof(f[now]));
        for (int j = 0; j < mod; j++) {
            (f[now][(j + t) % mod] += f[last][j]) %= MOD;
            (f[now][j] += f[last][j]) %= MOD;
        }
    }
    cout << (f[now][0] == 0 ? MOD - 1 : f[now][0] - 1) << endl;
    return 0;
}