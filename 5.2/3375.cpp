#include <iostream>
#include <cstring>

using namespace std;

const int L = 1000010;

char s1[L], s2[L];
int nxt[L];

int main() {
    ios::sync_with_stdio(false);
    cin >> s1 >> s2;
    int len1 = strlen(s1), len2 = strlen(s2);
    for (int k = 0, i = 1; i < len2; i++) {
        while(k && s2[i] != s2[k]) k = nxt[k];
        nxt[i + 1] = s2[i] == s2[k] ? ++k : 0;
    }
    for (int k = 0, i = 0; i < len1; i++) {
        while(k && s1[i] != s2[k]) k = nxt[k];
        if (s1[i] == s2[k]) k++;
        if (k == len2)
            cout << i + 2 - len2 << endl;
    }
    for (int i = 1; i <= len2; i++) {
        cout << nxt[i];
        if (i == len2) cout << endl;
        else cout << " ";
    }
    return 0;
}