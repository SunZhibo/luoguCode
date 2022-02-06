#include <iostream>
#include <cstdio>

using namespace std;

const int N = 101;
const int V = 201;

int n, M, T;
int f[V][V];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> M >> T;
    for (int t, m, i = 1; i <= n; i++) {
        cin >> m >> t;
        for (int j = M; j >= m; j--)
        for (int k = T; k >= t; k--)
            f[j][k] = max(f[j][k], f[j - m][k - t] + 1);
    }
    cout << f[M][T] << endl;
    return 0;
}