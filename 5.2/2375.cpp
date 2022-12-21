#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int K = 20;
const int L = 1000010;
const int mod = 1e9 + 7;

int n, len;
int kmp[L], st[K][L], sum[L];
char s[L];


int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    while(n--) {
        ll ans = 1;
        cin >> s, len = strlen(s);
        for (int k = 0, i = 1; i < len; i++) {
            while(k && s[i] != s[k]) k = kmp[k];
            if (s[i] == s[k])
                kmp[i + 1] = ++k, sum[i + 1] = sum[k] + 1;
            else
                kmp[i + 1] = sum[i + 1] = 0;
        }
        for (int i = 1; i <= len; i++)
            st[0][i] = kmp[i];
        for (int j = 1; j < K; j++)
        for (int i = 1; i <= len; i++)
            st[j][i] = st[j - 1][st[j - 1][i]];
        for (int i = len; i >= 1; i--) {
            int node = i, cnt = 0;
            if (!kmp[i]) continue;
            for (int j = K - 1; j >= 0; j--)
                if (st[j][node] * 2 > i)
                    node = st[j][node], cnt |= (1 << j);
            (ans *= (sum[i] - cnt + 1)) %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}