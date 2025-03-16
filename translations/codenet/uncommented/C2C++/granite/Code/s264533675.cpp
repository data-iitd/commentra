
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
        str[5] =' ';
        str[13] =' ';
    cout<<str<<endl;
    return 0;
}
