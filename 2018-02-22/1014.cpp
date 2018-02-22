#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int Time[1005];//每个人结束的时间
int ans[1005];

int main()
{
    int n,m,t,q;
    cin>>n>>m>>t>>q;
    for(int i=1;i<=t;i++)
        cin>>Time[i];
    queue<int> que[n];
    for(int i=1;i<=t;i++)//先把黄线以内的放进队列中
    {
        if(i>n*m)break;
        que[i%n].push(i);
    }
    int k=0;
    if(t>n*m)k=m*n+1;//从黄线以外开始计数
    int i=1;
    while(i<=539)//因为是开始服务的时间不能超过17点，而不是完成的时间，所以先算到539分钟，最后一分钟再把每个队列头的元素拿出来
    {
        for(int j=0;j<n;j++)
        {
            if(que[j].empty())continue;
            int tem=que[j].front();

            if(Time[tem]==i)
            {
                que[j].pop();
                if(!que[j].empty())Time[que[j].front()]+=i;
                ans[tem]=i;
                if(k>0&&k<=t)
                {if(que[j].empty())
                    Time[k]+=i;
                    que[j].push(k++);
                }

            }
        }
        i++;
    }
    for(int i=0;i<n;i++)//把每个队列头的元素拿出来，这也是符合要求的
    {
        if(que[i].empty())continue;
        ans[que[i].front()]=Time[que[i].front()];
    }

    for(int i=1;i<=q;i++)
    {
        int a;
        cin>>a;
        if(ans[a]==0)
        {
            cout<<"Sorry"<<endl;continue;
        }
        int hh=ans[a]/60+8;
        int ss=ans[a]%60;
        printf("%02d:%02d\n",hh,ss);
    }


}
