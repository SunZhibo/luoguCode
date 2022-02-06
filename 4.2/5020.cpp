#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 101;
const int V = 25001;

int T, n;
int a[N]; bool f[V];

int main() {
    cin >> T;
    while(T--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        int ans = 0;
        memset(f, 0, sizeof(f)), f[0] = true;
        for (int i = 1; i <= n; i++) {
            if (f[a[i]]) continue;
            for (int j = a[i]; j <= a[n]; j++)
                f[j] |= f[j - a[i]];
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}