#include <iostream>
using namespace std;

int main()
{
    int i=1,Input;
    while(1)
    {
        cin>>Input;
        if(Input==0)
        {
            break;
        }
        cout<<"Case "<<i<<": "<<Input<<endl;
        i++;
    }
    return 0;
}
