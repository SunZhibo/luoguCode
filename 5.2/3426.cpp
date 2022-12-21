#include <iostream>
#include <cstring>

using namespace std;

const int L = 500010;

char s[L];
int nxt[L], f[L], bucket[L];

int main() {
    ios::sync_with_stdio(false);
    cin >> s;
    int len = strlen(s);
    for (int k = 0, i = 1; i < len; i++) {
        while(k && s[i] != s[k]) k = nxt[k];
        nxt[i + 1] = s[i] == s[k] ? ++k : 0;
    }
    for (int i = 1; i <= len; i++) {
        f[i] = i;
        if (nxt[i]) {
            int t = f[nxt[i]];
            if (bucket[t] + t >= i)
                f[i] = t;
        }
        bucket[f[i]] = i;
    }
    cout << f[len] << endl;
    return 0;
}