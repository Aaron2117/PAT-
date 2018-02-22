#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    double ans=1;
    for(int i=1;i<=2;i++)
    {
        double a,b,c;
        cin>>a>>b>>c;
        if(a>=b&&a>=c)
        {
            cout<<"W ";
        ans*=a;
        }
            else if(b>=c&&b>=a)
            {
                cout<<"T ";
                ans*=b;
            }
            else
            {
                cout<<"L ";
                ans*=c;
            }
    }
    double a,b,c;
        cin>>a>>b>>c;
        if(a>=b&&a>=c)
        {
            cout<<"W";
        ans*=a;
        }
            else if(b>=c&&b>=a)
            {
                cout<<"T";
                ans*=b;
            }
            else
            {
                cout<<"L";
                ans*=c;
            }
        printf(" %.2f",(ans*0.65-1)*2);
}
