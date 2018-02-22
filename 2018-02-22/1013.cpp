#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n,m,k;
int ma[1005][1005];
int ans;
int used[1005];
void dfs(int x)
{
    for(int i=1;i<=n;i++)
    {

        if(!used[i]&&ma[i][x]==1)//联通
        {
            used[i]=1;
            dfs(i);
        }
    }
}

int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        ma[a][b]=1;
        ma[b][a]=1;
    }
    for(int i=1;i<=k;i++)
    {
        memset(used,0,sizeof(used));
        ans=0;
        int t;
        cin>>t;
        for(int i=1;i<=n;i++)//将与t有关的路封死
        {
            ma[t][i]+=10;
            ma[i][t]+=10;
        }
        for(int i=1;i<=n;i++)
        {
            if(!used[i])
            {
                dfs(i);
                ans++;
            }
        }
        cout<<ans-2<<endl;
        for(int i=1;i<=n;i++)//将与t有关的路封死
        {
            ma[t][i]-=10;
            ma[i][t]-=10;
        }
    }
}
