#include <iostream>
#include <string>
using namespace std;
int main()
{
    long a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    int len=s.length();
    int sum=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]!='.')
        {
            sum=sum*10+s[i]-'0';
        }
    }
    cout<<a*sum/100<<endl;
    return 0;
}
