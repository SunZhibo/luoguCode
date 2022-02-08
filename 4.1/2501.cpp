#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 35001;
const ll inf = 1e18;

int n, len;
int a[N], f[N], minval[N];
vector<int> pos[N];
ll sum[N], sub[N], pre[N], g[N];

int bin(vector<int> p, int index) {
    int l = 0, r = p.size() - 1, mid, res;
    while(l <= r) {
        mid = (l + r) / 2;
        if (a[p[mid]] <= a[index])
            res = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] -= i;
    for (int i = 1; i <= n; i++) {
        int p = upper_bound(minval + 1, minval + len + 1, a[i]) - minval;
        if (p == len + 1) len++;
        minval[p] = a[i], f[i] = p;
    }
    cout << n - len << endl;
    for (int r = 1; r <= n; r++) {
        if (f[r] == 1)
            g[r] = sum[r - 1] - 1ll * (r - 1) * a[r];
        else {
            int val = f[r] - 1, index = bin(pos[val], r);
            sub[r] = 0, g[r] = inf;
            for (int i = r - 1; i > pos[val][index]; i--)
                sub[i] = sub[i + 1] + abs(a[i] - a[r]);
            for (int i = pos[val].size() - 1; i >= index; i--) {
                int p = pos[val][i];
                pre[p - 1] = 0;
                for (int j = p; j < r; j++) {
                    pre[j] = pre[j - 1] + abs(a[j] - a[p]);
                    g[r] = min(g[r], g[p] + pre[j] + sub[j + 1]);
                }
            }
        }
        pos[f[r]].push_back(r);
        sum[r] = sum[r - 1] + a[r];
    }
    ll ans = inf;
    for (int i = 1; i <= n; i++)
        if (f[i] == len) {
            g[i] += 1ll * (n - i) * a[i] - (sum[n] - sum[i]);
            ans = min(ans, g[i]);
        }
    cout << ans << endl;
    return 0;
}