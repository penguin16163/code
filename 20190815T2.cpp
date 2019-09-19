#include<bits/stdc++.h>
using namespace std;
char a[20][20];
int n, m,ans;
bool vis[20][20];
int dis[20][20];
struct node {
    int x, y;
};
queue <node> q;
inline void xxr(int x, int y)
{
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    node now,nxt;
    now.x=x,now.y=y;
    q.push(now);
    while (!q.empty()) {
        now=q.front();
        q.pop();
        if (a[now.x+1][now.y]=='#' && vis[now.x+1][now.y]==0 && now.x+1<=n) {
            dis[now.x+1][now.y]=dis[now.x][now.y]+1;
            vis[now.x+1][now.y]=1;
            nxt.x=now.x+1,nxt.y=now.y;
            q.push(nxt);
        }
        if (a[now.x-1][now.y]=='#' && vis[now.x-1][now.y]==0 && now.x-1>0) {
            dis[now.x-1][now.y]=dis[now.x][now.y]+1;
            vis[now.x-1][now.y]=1;
            nxt.x=now.x-1,nxt.y=now.y;
            q.push(nxt);
        }
        if (a[now.x][now.y+1]=='#' && vis[now.x][now.y+1]==0 && now.y+1<=m) {
            dis[now.x][now.y+1]=dis[now.x][now.y]+1;
            vis[now.x][now.y+1]=1;
            nxt.x=now.x,nxt.y=now.y+1;
            q.push(nxt);
        }
        if (a[now.x][now.y-1]=='#' && vis[now.x][now.y-1]==0 && now.y-1>0) {
            dis[now.x][now.y-1]=dis[now.x][now.y]+1;
            vis[now.x][now.y-1]=1;
            nxt.x=now.x,nxt.y=now.y-1;
            q.push(nxt);
        }
    }
    int s=-1;
    for (int i=1; i<=n; ++i) 
        for (int j=1; j<=m; ++j)
            if (dis[i][j]>s) s=dis[i][j];
    if (s<ans) ans=s;
             
}
int main()
{
    scanf("%d %d", &n, &m);
    for (register int i=1; i<=n; ++i) 
        for (register int j=1; j<=m; ++j) {
            cin>>a[i][j];
        }
    for (register int i=1; i<=n; ++i)  {
        for (register int j=1; j<=m; ++j) {
            xxr(i,j);
        }
    }
    printf("%d", ans);
}
