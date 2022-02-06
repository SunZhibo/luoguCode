#include <iostream>
#include <cstdio>
using namespace std;
const int N=27;
const int MAXN=30001;
int n,m;   int v[N],w[N];   int F[MAXN];
void read()
{
    int i;
    scanf("%d%d",&m,&n);
    for (i=1;i<=n;i++)
        scanf("%d%d",&v[i],&w[i]);
    return;
}
void dp()
{
    int i,j;
    for (i=1;i<=n;i++)
        for (j=m;j>=v[i];j--)
            F[j]=max(F[j],F[j-v[i]]+v[i]*w[i]);
    printf("%d\n",F[m]);
    return;
}
int main()
{
    read();
    dp();
    return 0;
}