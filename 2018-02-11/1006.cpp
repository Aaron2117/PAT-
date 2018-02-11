#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node
{
    char id[18];
    int siin[3];
    int siout[3];
}no[111];

int n;
bool cmp1(node a,node b)
{
    if( a.siin[0]<b.siin[0])return true;
    else if(a.siin[0] == b.siin[0])
    {
        if(a.siin[1]<b.siin[1])
            return true;
        else if(a.siin[1] ==b.siin[1])
            return a.siin[2]<=b.siin[2];
    }
    return false;
}

bool cmp2(node a,node b)
{
    if( a.siout[0]<b.siout[0])return true;
    else if(a.siout[0] == b.siout[0])
    {
        if(a.siout[1]<b.siout[1])
            return true;
        else if(a.siout[1] ==b.siout[1])
            return a.siout[2]<=b.siout[2];
    }
    return false;
}

int main()
{
   // freopen("1.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>no[i].id;
        char begin[15],end[15];
        cin>>begin>>end;
        no[i].siin[0]=(begin[0]-'0')*10+begin[1]-'0';
        no[i].siin[1]=(begin[3]-'0')*10+begin[4]-'0';
        no[i].siin[2]=(begin[6]-'0')*10+begin[7]-'0';
        no[i].siout[0]=(end[0]-'0')*10+end[1]-'0';
        no[i].siout[1]=(end[3]-'0')*10+end[4]-'0';
        no[i].siout[2]=(end[6]-'0')*10+end[7]-'0';
    }
    sort(no+1,no+1+n,cmp1);
    cout<<no[1].id<<" ";
    sort(no+1,no+1+n,cmp2);
    cout<<no[n].id;
}
