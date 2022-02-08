#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1010;

int n, ans;
int a[N][N], b[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];
        for (int j = 1; j <= i; j++)
            b[i][j] = max(b[i - 1][j - 1], b[i - 1][j]) + a[i][j];
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, b[n][i]);
    cout << ans << endl;
    return 0;
}