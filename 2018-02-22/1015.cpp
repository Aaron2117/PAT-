#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include<cmath>

using namespace std;

int pri[100005];
void prim()
{
    pri[1]=1;
    for(int i=2;i<=100005;i++)
    {
        if(pri[i])continue;
        for(int j=i*2;j<=100005;j+=i)
            if(j%i==0)pri[j]=1;
    }
}

int change(int n,int d)
{
    int tem[105];int k=0;
    while(n)
    {
        tem[k++]=n%d;
        n/=d;
    }
    int ans=0;
    for(int i=k;i>0;i--)
    {
        ans=ans*d+tem[k-i];
    }
    return ans;
}

int main()
{
    int n,d;prim();
    while(cin>>n)
    {
        if(n<0)break;
        cin>>d;
        int m=change(n,d);

        if(!pri[m]&&!pri[n])
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

}
