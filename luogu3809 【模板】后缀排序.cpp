/*
��Ŀ����
����һ������Ϊ n n ���ɴ�СдӢ����ĸ��������ɵ��ַ������������ַ��������зǿպ�׺���ֵ����С��������Ȼ��˳�������׺�ĵ�һ���ַ���ԭ���е�λ�á�λ�ñ��Ϊ 1 1 �� n n��

�����ʽ
һ��һ������Ϊ n n �Ľ�������СдӢ����ĸ�����ֵ��ַ�����

�����ʽ
һ�У���n����������ʾ�𰸡�
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
      int m=150;//ȷ���߽� 
      //����һ���������
      for(int i=1;i<=n;++i)t[x[i]=a[i]]++;//����Ͱ�� 
      for(int j=1;j<=m;++j)t[j]+=t[j-1];//����λ�� 
      for(int i=n;i>=1;--i)SA[t[x[i]]--]=i;//����     
      //���ñ�����������
      for(int k=1;k<=n;k<<=1)
      {
               int p=0;
               for(int i=0;i<=m;++i)y[i]=0;//Ͱ���
             for(int i=n-k+1;i<=n;++i)y[++p]=i;
                       //�����kλ����ͱ���γɶ�Ԫ��,ֱ�Ӽ����Ԫ��ĵڶ�λ 
             for(int i=1;i<=n;++i)if(SA[i]>k)y[++p]=SA[i]-k;
             for(int i=0;i<=m;++i)t[i]=0;//Ͱ���
             for(int i=1;i<=n;++i)t[x[y[i]]]++;
             for(int i=1;i<=m;++i)t[i]+=t[i-1];//����λ��
             for(int i=n;i>=1;--i)SA[t[x[y[i]]]--]=y[i];//����
             swap(x,y);//����Ͱ
             x[SA[1]]=p=1;
             for(int i=2;i<=n;++i)
                 x[SA[i]]=cmp(SA[i],SA[i-1],k)?p:++p;
             if(p>=n)break;//���ü���������
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
