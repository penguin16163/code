/*
题目描述
读入一个长度为 n n 的由大小写英文字母或数字组成的字符串，请把这个字符串的所有非空后缀按字典序从小到大排序，然后按顺序输出后缀的第一个字符在原串中的位置。位置编号为 1 1 到 n n。

输入格式
一行一个长度为 n n 的仅包含大小写英文字母或数字的字符串。

输出格式
一行，共n个整数，表示答案。
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 2000000
string s;
int n;
int SA[MAX];
int t[MAX],x[MAX],a[MAX],y[MAX];
inline bool cmp(int i,int j,int k)
{
       return y[i]==y[j]&&y[i+k]==y[j+k];
}
int get_SA()
{
      int m=150;//确定边界 
      //首先一遍基数排序
      for(int i=1;i<=n;++i)t[x[i]=a[i]]++;//放入桶中 
      for(int j=1;j<=m;++j)t[j]+=t[j-1];//计算位数 
      for(int i=n;i>=1;--i)SA[t[x[i]]--]=i;//排序     
      //利用倍增继续排序
      for(int k=1;k<=n;k<<=1)
      {
               int p=0;
               for(int i=0;i<=m;++i)y[i]=0;//桶清空
             for(int i=n-k+1;i<=n;++i)y[++p]=i;
                       //后面的k位不会和别的形成二元组,直接计算二元组的第二位 
             for(int i=1;i<=n;++i)if(SA[i]>k)y[++p]=SA[i]-k;
             for(int i=0;i<=m;++i)t[i]=0;//桶清空
             for(int i=1;i<=n;++i)t[x[y[i]]]++;
             for(int i=1;i<=m;++i)t[i]+=t[i-1];//计算位数
             for(int i=n;i>=1;--i)SA[t[x[y[i]]]--]=y[i];//排序
             swap(x,y);//交换桶
             x[SA[1]]=p=1;
             for(int i=2;i<=n;++i)
                 x[SA[i]]=cmp(SA[i],SA[i-1],k)?p:++p;
             if(p>=n)break;//不用继续排序了
             m=p; 
      }
      for(int i=1;i<=n;++i)
        printf("%d ",SA[i]);
}
int main()
{
      cin>>s;
      int l=s.length();
      n=l;
      for(int i=1;i<=l;++i)
          a[i]=s[i-1];
      get_SA();
      return 0; 
}
