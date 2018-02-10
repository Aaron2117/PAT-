#include <iostream>
#include <cstdio>
using namespace std;

int father[105];
int ans[1005];
int deepest;

int n,m;
void dfs(int fa,int deep)
{
    bool flag=true;//判断是不是有儿子
    for(int i=1;i<=n;i++)
        if(father[i]==fa)
        {
            dfs(i,deep+1);
            flag=false;
        }
    if(flag)//如果没有儿子;
    {
        ans[deep]++;
        deepest=max(deepest,deep);
    }

}

int main()
{

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        father[i]=-1;
    for(int i=1;i<=m;i++)
    {
        int fa,k;
        cin>>fa>>k;
        for(int j=1;j<=k;j++)
        {
            int t;
            cin>>t;
            father[t]=fa;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(father[i]==-1)//是祖先就dfs
            dfs(i,1);
    }
    cout<<ans[1];
    for(int i=2;i<=deepest;i++)
        cout<<" "<<ans[i];
}
