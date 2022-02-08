#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1000010;

int n, a[N], f[N][3];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(f, 0x7f, sizeof(f));
    f[1][a[1] + 1] = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] == -1) {
            f[i][0] = f[i - 1][0];
            f[i][2] = f[i - 1][2] + 2;
        } else if (a[i] == 0) {
            f[i][0] = f[i - 1][0] + 1;
            f[i][1] = min(f[i - 1][0], f[i - 1][1]);
            f[i][2] = f[i - 1][2] + 1;
        } else {
            f[i][0] = f[i - 1][0] + 2;
            f[i][1] = f[i - 1][0] + 1;
            f[i][2] = min(f[i - 1][2], min(f[i - 1][0], f[i - 1][1]));
        }
    }
    int ans = min(f[n][0], min(f[n][1], f[n][2]));
    if (ans >= 0x7f7f7f7f) cout << "BRAK" << endl;
    else cout << ans << endl;
    return 0;
}
