#include<bits/stdc++.h>
using namespace std;
int n, x, y;
int edge[100005][600],cnt[100005],s[100005],ans[100005],a[100005],b[100005],f[100005];
void xxr(int k)
{
    ans[k]=s[b[k]];
    s[b[k]]+=a[k];
    for (int i=1; i<=cnt[k]; ++i) {
        if (f[k]!=edge[k][i]) {
            f[edge[k][i]]=k;
            xxr(edge[k][i]);
        }
    }
    ans[k]=s[b[k]]-ans[k];
}
int main()
{
    //freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    scanf("%d", &n);
    for (register int i=1; i<=n; ++i) 
        scanf("%d%d", &a[i], &b[i]);
    for (register int i=1; i<=n-1; ++i) {
        scanf("%d%d", &x, &y);
        edge[x][++cnt[x]]=y;
        edge[y][++cnt[y]]=x;
    }
    xxr(1);
    for (register int i=1; i<=n; ++i) 
        printf("%d ",ans[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}