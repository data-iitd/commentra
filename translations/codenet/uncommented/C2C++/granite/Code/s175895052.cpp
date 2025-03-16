
#include<iostream>
using namespace std;

int main(void)
{
    char n[10];
    cin>>n;
    if(((n[0]==n[1])&&(n[1]==n[2]))||((n[1]==n[2])&&(n[2]==n[3])))
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
    return 0;
}
