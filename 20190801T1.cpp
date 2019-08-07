#include<bits/stdc++.h>
#define re register
using namespace std;
long long a[200005],f[200005];
long long s;
int n,m,ty,l,r;
int main()
{
	scanf("%d %d",&n,&m);
	f[1]=f[2]=1;
	for (re int i=3; i<=n; ++i)
	    f[i]=f[i-1]+f[i-2];
	for (re int t=1; t<=m; ++t) {
		scanf("%d %d %d",&ty,&l,&r);
		if (ty==1) {
			for (re int j=l; j<=r; ++j) {
				a[j]+=f[j-l+1];
			}
		}
		else {
			s=0;
			for (re int j=l; j<=r; ++j) {
				s+=a[j]*a[j];
			}
		    printf("%lld\n",s);	
		}
	}
}
