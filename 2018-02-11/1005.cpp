#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int father[105];
int ans[1005];
int deepest;

int n,m;



void solve(int k)
{
    if(k==1)
        cout<<"one";
    else if(k==2)
        cout<<"two";
    else if(k==3)
    cout<<"three";
    else if(k==4)
        cout<<"four";
    else if(k==5)
        cout<<"five";
    else if(k==6)
        cout<<"six";
    else if(k==7)
        cout<<"seven";
    else if(k==8)
        cout<<"eight";
    else if(k==9)
        cout<<"nine";
    else if(k==0)
        cout<<"zero";
}

int main()
{
    char ch[105];
    cin>>ch;
    int ans1[1005];
    int ans=0;
    for(int i=0;i<strlen(ch);i++)
     ans+=ch[i]-'0';
     int k=0;
    while(ans)
    {
        ans1[++k]=ans%10;
        ans/=10;
    }
    solve(ans1[k]);
    for(int i=k-1;i>=1;i--)
    {
        cout<<" ";
        solve(ans1[i]);
    }

}
