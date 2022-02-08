#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, len, ans;
int h[N], maxh[N], minh[N];

int main() {
    ios::sync_with_stdio(false);
    while(cin >> h[++n]); n--;
    for (int i = 1; i <= n; i++) {
        int p = upper_bound(maxh + 1, maxh + len + 1, h[i], greater<int>()) - maxh;
        if (p == len + 1) len++;
        maxh[p] = h[i];
    }
    for (int i = 1; i <= n; i++) {
        int p = lower_bound(minh + 1, minh + ans + 1, h[i]) - minh;
        if (p == ans + 1) ans++;
        minh[p] = h[i];
    }
    cout << len << endl << ans << endl;
    return 0;
}