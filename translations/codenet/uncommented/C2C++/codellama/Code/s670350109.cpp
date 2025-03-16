#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str1,str2,temp;
    cin>>str1;
    cin>>str2;
    int i,j=0,t;
    t=str1.length();
    if(str1.length()!=str2.length())
    {
        cout<<"NO\n";
    }
    else
    {
        while(str1[j]!='\0')
        {
            temp[j]=str1[t];
            j++;
            t--;
        }
        t=0;
        i=0;
        while(temp[i]!='\0')
        {
            if(temp[i]==str2[i])
            {
                t++;
            }
            i++;
        }
        if(str2.length()==t)
        {
            cout<<"YES\n";
        }
        else if(str2.length()!=t)
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
