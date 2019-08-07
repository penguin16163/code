#include<cstdio>
#include<deque>
using namespace std;
deque<int>d[200001],p,h[200001];
int o[200001],a[200001],b[200001],x,y,n,q,t,i,f[200001],g[200001];
void dfs(int x){
	o[x]=h[b[x]].back();h[b[x]].push_back(x);
	if(!d[x].empty())for(deque<int>::iterator i=d[x].begin();i!=d[x].end();i++)dfs(*i);
	h[b[x]].pop_back();
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d %d",&a[i],&b[i]);
	for(i=1;i<n;i++)scanf("%d %d",&x,&y),d[x].push_back(y),f[y]++;
	p.push_back(1);
	for(i=1;i<=n;i++)h[i].push_back(0);
	while(!p.empty()){
		q=p.front();p.pop_front();
		f[++t]=q;for(deque<int>::iterator i=d[q].begin();i!=d[q].end();i++)p.push_back(*i);
	}
	dfs(1);
	for(i=n;i>=1;i--)g[i]=a[i],a[o[i]]+=a[i];
	for(i=1;i<=n;i++)printf("%d ",g[i]);
}