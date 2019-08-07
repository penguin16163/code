#include <bits/stdc++.h>
using namespace std;
const int N = 10000005;
struct node {
    int lson, rson, tag;
    long long sum; 
};
node tree[N*4];
int m, n, x, y, z;
int a[N], root[N], tot, cnt;
inline void pushup(int x) {
    tree[x].sum=tree[tree[x].lson].sum+tree[tree[x].rson].sum;
}
void build(int &k, int l, int r) {
    k=++tot;
    if (l == r) {
        tree[k].sum=a[k];
        return;
    }
    int mid=l+r>>1;
    build(tree[k].lson,l,mid);
    build(tree[k].rson,mid+1,r);
    pushup(k);
}
void update(int &k,int last, int l, int r, int x, int y, int z) {
    k=++tot;
    tree[k].tag=tree[last].tag;
    
    tree[k].lson=tree[last].lson;
    tree[k].rson=tree[last].rson;
    if (x<=l && y>=r) {
        tree[k].sum=tree[last].sum+z*(r-l+1);
        tree[k].tag=tree[last].tag+z;
        return;
    }
    int mid=l+r>>1;
    if (x<=mid) update(tree[k].lson,tree[last].lson,l,mid,x,y,z);
    if (y>mid) update(tree[k].rson,tree[last].rson,mid+1,r,x,y,z);
    pushup(k);
}
long long query(int k, int l, int r, int x, int y) {
    if (k == 0) return 0;
    if (x<=l && r<=y) return tree[k].sum;
    int mid=l+r>>1;
    long long ans=tree[k].tag*(min(y,r)-max(x,l)+1);
    if (x<=mid) ans+=(tree[k].lson,l,mid,x,y);
    if (y>mid) ans+=(tree[k].rson,mid+1,r,x,y);
    return ans;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    build(root[0], 1, n);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &x);
        if (x == 1) {
            scanf("%d %d %d", &x, &y, &z);
            update(root[++cnt],root[cnt-1],1,n,x,y,z);
        }
        if (x == 2) {
            scanf("%d",&y);
            root[++cnt]=root[y];
        }
        if (x == 3) {
            scanf("%d %d",&y, &z);
            printf("%lld\n",query(root[cnt],1,n,y,z));
        }
    }
    return 0;
}