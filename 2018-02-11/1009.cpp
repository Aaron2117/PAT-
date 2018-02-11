#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

double poly1[2005];//保存系数
double poly2[2005];
double ans[2005];
int num1[2005];
int num2[2005];


int n,m;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;double b;
        cin>>a>>b;
        num1[i]=a;
        poly1[a]=b;
    }
    cin>>m;
for(int i=1;i<=m;i++)
    {
        int a;double b;
        cin>>a>>b;
        num2[i]=a;
        poly2[a]=b;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        ans[num1[i]+num2[j]]+=poly1[num1[i]]*poly2[num2[j]];
    }
    int t=0;
    for(int i=2000;i>=0;i--)
        if(ans[i])t++;
    cout<<t;
    for(int i=2000;i>=0;i--)
        if(ans[i])
        {
            printf(" %d %.1f",i,ans[i]);
           // cout<<i<<" "<<ans[i];
        }
}
