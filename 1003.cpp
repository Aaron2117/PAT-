#include <iostream>
#include <cstdio>
using namespace std;

int ma[505][505];
int v[505];
int vis[505];
int dis[505];
int num[505];
int va[505];
int n,m,c1,c2;

int INF=99999999;

void dijkstra(int c1)
{
    for(int i=0;i<n;i++)
    {
        dis[i]=ma[c1][i];
        vis[i]=0;
        num[i]=1;
        if(dis[i]!=INF)
            va[i]=v[c1]+v[i];
    }
        vis[c1]=1;
    for(int i=0;i<=n;i++)
    {
        int minn=INF,temp=-1;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&minn>dis[j])
            {
                minn=dis[j];
                temp=j;
            }
        }
        //cout<<temp<<" "<<dis[temp]<<" "<<num[temp]<<endl;
        if(temp==-1)break;
        vis[temp]=1;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&dis[j]>dis[temp]+ma[temp][j])
            {
                dis[j]=dis[temp]+ma[temp][j];
                num[j]=num[temp];
                va[j]=va[temp]+v[j];
            }
           else if(!vis[j]&&dis[j]==dis[temp]+ma[temp][j])
           {
               num[j]++;
               va[j]=max(va[j],va[temp]+v[j]);
           }

        }
    }
}

int main()
{
    freopen("1.txt","r",stdin);
    cin>>n>>m>>c1>>c2;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(i!=j)ma[i][j]=INF;
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        ma[a][b]=ma[b][a]=min(ma[a][b],c);
    }
    dijkstra(c1);
    if(c1==c2)
        cout<<1<<" "<<v[c1];
    else
    cout<<num[c2]<<" "<<va[c2];
}
