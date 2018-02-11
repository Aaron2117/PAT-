#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int ma[105];
int n;

int main()
{
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
         cin>>ma[i];
         if(ma[i]>ma[i-1])
         ans+=(ma[i]-ma[i-1])*6;
         else
            ans+=(ma[i-1]-ma[i])*4;
         ans+=5;
    }
    cout<<ans<<endl;



}
