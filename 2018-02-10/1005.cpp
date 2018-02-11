#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int ma[10005];
int sum[10005];//前缀和

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>ma[i];
        sum[i]=sum[i-1]+ma[i];
    }
    int maxx=-99999999;
    int be1=1,end1=1;
    for(int i=n;i>=1;i--)
        for(int j=i-1;j>=0;j--)
    {
        if(sum[i]-sum[j]>=maxx)
        {
            maxx=sum[i]-sum[j];
            be1=ma[j+1];
            end1=ma[i];
            //cout<<maxx<<" "<<be1<<" "<<end1<<endl;
        }
    }
    if(maxx>=0)
    cout<<maxx<<" "<<be1<<" "<<end1;
    else
        cout<<0<<" "<<ma[1]<<" "<<ma[n];
}
