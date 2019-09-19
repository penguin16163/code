#include<bits/stdc++.h>
using namespace std;
int a[1000],b[1000],n,ans,total,q[1000];
bool f[1000];
void xxr(int now, int k, int cnt)
{
    f[now]=1;
    if (now==k && cnt!=0) {
        ++total;
        if (cnt>ans) ans=cnt;
        return ;
    }
    for (int i=1; i<=n; ++i) {
        if (b[i]==now && q[now]!=i) xxr(a[i], k, ++cnt);
    }
} 
int main()
{
    freopen("handkerchief.in","r",stdin);
    freopen("handkerchief.out","w",stdout);
    scanf("%d", &n);
    for (register int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        q[a[i]]=i;
    }
    for (register int i=1; i<=n; ++i) scanf("%d", &b[i]);
    for (register int i=1; i<=n; ++i) 
        if (f[a[i]]==0) {
            xxr(a[i],a[i],0);
        }    
    printf("%d ", total);
    if (total==0) puts("-1");
    else printf("%d", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}