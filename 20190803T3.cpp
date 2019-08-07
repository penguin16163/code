#include<bits/stdc++.h>
using namespace std;
int T,n,k,cnt;
int s[13],f[13],x[501],y[501],a[501][501],p[501];
void check(int x)
{
	int j=n;
	cnt++;
	for(register int i=x; i>=1; --i) {
		while (p[i]!=j && j>0) {
            --j;
            y[cnt]*=2;
        }
		y[cnt]++;
	}
	while (j>1) {
        y[cnt]*=2;
        --j;
    }
}
void xxr(int x,int y)
{
	if(x==y+1){
		check(y);
		return;
	}
	for(register int i=p[x-1]+1; i<=k; ++i){
		if (cnt==n) return;
		p[x]=i;
		xxr(x+1,y);
    }
}
int main()
{
    s[0]=s[1]=1;
    for (register int i=2; i<=12; ++i) 
        s[i]=s[i-1]*i;
    for (register int i=1; i<=12; ++i) 
        f[i]=s[i]/(s[i>>1]*s[i>>1]);
    scanf("%d", &T);
    while (T--) {
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        memset(a,0,sizeof(a));
        cnt=0;
        scanf("%d", &n);
        k=1;
        while (f[k]<n) ++k;
        xxr(1,k/2);
        for (register int i=1; i<=n; ++i)
            x[i]=(1<<k)-1-y[i];
        for (register int i=1; i<=n; ++i) {
            for (register int j=1; j<=n; ++j) {
                if (i!=j) {
                    int z=y[i]&x[j];
                    for (register int l=1; l<=n; ++l) {
                        if (z&(1<<(l-1))) {
                            a[i][j]=l;
                            break;
                        }
                    }
                }
            }
        }
        for (register int i=1; i<=n; ++i) {
            for (register int j=1; j<=n; ++j) {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
}