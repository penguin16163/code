#include<bits/stdc++.h>
#define N 20005
using namespace std;
int l, r, n, v, ls, rs, lw, rw, tmp;
struct node {
    int s, w;
};
node a[N], c[N];
inline bool cmp1(node x, node y) {
    return x.s > y.s;
}
inline bool cmp2(node x, node y) {
    return x.w < y.w;
}
int main()
{
    scanf("%d %d %d %d", &l, &r, &n, &v);
    for (int i=1; i<=n; ++i) {
        scanf("%d", &a[i].s, &a[i].w);
        c[i]=a[i];
    }
    sort(a+1, a+n+1, cmp1);
    sort(c+1, c+n+1, cmp2);
    for (int t=l; t<=r-2; ++t) {
        tmp=t/2;
        for (int i=1+tmp; i<=n-tmp; ++i) {
            ls=0,rs=0,lw=0,rw=0;
            for (int j=1; j<n; ++j) {
                if (a[j].s<a[i].s && ls<tmp) ++ls, lw+=a[j].w;
                if (a[j].s>a[i].s && rs<tmp) ++rs, rw+=a[j].w;
            }
            if (ls==tmp && rs==tmp && lw+rw<=v) {
                printf("%d ", a[i].s);
                break;
            }
        }
    }
}