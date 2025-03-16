#include<iostream>
using namespace std;
int main()
{
    char str[30];
    cin.getline(str, 30);
    str[5] =' ';
    str[13] =' ';
    cout << str << endl;
    return 0;
}
