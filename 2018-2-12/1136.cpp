#include <iostream>
#include <cstring>
using namespace std;

bool judge(char * ch,int len)
{

    for(int i=0;i<=len/2;i++)
    {
        if(ch[i]!=ch[len-i-1])
            return false;
    }
    return true;
}
char ch[1005];
    char ch1[1005];
int main()
{

    cin>>ch;

    int len=strlen(ch);int t=0;

    for(int i=0;i<len;i++)
        ch1[i]=ch[i];

    for(int i=0;i<len/2;i++)
        swap(ch[i],ch[len-i-1]);
    ch[len]=0;
    while(!judge(ch,len))
    {
        if(t==10)break;
        for(int i=len-1;i>=0;i--)
        cout<<ch[i];
    cout<<" + ";
    for(int i=0;i<=len-1;i++)
        cout<<ch[i];
        cout<<" = ";
        for(int i=0;i<len;i++)
        {
            int sum=ch[i]+ch1[i]-'0'-'0';
            //cout<<sum<<endl;
            if(sum >9)
            {

                ch[i+1]++;
            sum-=10;
            if(i+1==len)ch[i+1]+='0';
            }

           // cout<<ch[i]<<" "<<ch1[i]<<" "<<sum<<endl;
            ch[i]=sum+'0';

        }
        if(ch[len])len++;
        for(int i=0;i<len;i++)
        {
            ch1[i]=ch[len-i-1];
            cout<<ch1[i];
        }
        cout<<endl;
        t++;
    }
    if(judge(ch,len))
    {
        for(int i=0;i<len;i++)
            cout<<ch[i];
        cout<<" is a palindromic number.";
    }
    else
        cout<<"Not found in 10 iterations.";
}
