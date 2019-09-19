#include<bits/stdc++.h>
#define maxN 20005
using namespace std;
int l,r,n,v,ans;
struct node {
    int s, w;
}a[maxN],c[maxN];
inline bool cmp1(node x, node y) 
{
    return x.s > y.s;
}
inline bool cmp2(node x, node y)
{
    return x.w < y.w;
}
int main()
{
    scanf("%d %d %d %d", &l, &r, &n, &v);
    for (register int i=1; i<=n; ++i) {
        scanf("%d %d", &a[i].s, &a[i].w);
        c[i].s=a[i].s,c[i].w=a[i].w;
    }
    sort(a+1, a+n+1, cmp1);
    sort(c+1, c+n+1, cmp2);
    while (l<=r) {
        int rr=n-l/2,ll=1+l/2;
        for (register int i=rr; i>=ll; --i) {
            int lw=0,rw=0,ls=0, rs=0;
            for (register int j=1; j<=n; ++j) {
                if (ls!=l/2) {
                    if (c[j].s<a[i].s) {
                        lw+=c[j].w;
                        ++ls;
                    }
                }
                if (rs!=l/2) {
                    if (c[j].s>a[i].s) {
                        rw+=c[j].w;
                        ++rs;
                    }
                } 
                if (ls==l/2 && rs==l/2) break;
            }
            if (ls==l/2 && rs==l/2) {
                if (lw+rw<v) printf("%d\n",a[i].s);
                break;
            }
        } 
        l+=2;
    }
}