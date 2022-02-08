#include <iostream>
#include <cstdio>
#include <functional>
#include <algorithm>

using namespace std;

const int N = 110;

int h[N];

int solve(int l, int r, int val, function<bool(int, int)> comp) {
    static int len;
    static int f[N];
    len = 0;
    for (int i = l; i <= r; i++) {
        if (h[i] >= val) continue;
        int p = lower_bound(f + 1, f + len + 1, h[i], comp) - f;
        if (p == len + 1) len++;
        f[p] = h[i];
    }
    return len;
}

int main() {
    int ans = 0, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int mid = 1; mid <= n; mid++)
        ans = max(ans, solve(1, mid - 1, h[mid], less<int>()) + solve(mid + 1, n, h[mid], greater<int>()) + 1);
    cout << n - ans << endl;
    return 0;
}