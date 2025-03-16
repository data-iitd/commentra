#include <iostream>
#include <string>
using namespace std;
int main()
{
    string txt;
    cin >> txt;
    int cu = 0, cl = 0;
    for (int i = 0; i < txt.length(); i++)
    {
        if (islower(txt[i]))
        {
            cl++;
        }
        else
        {
            cu++;
        }
    }
    if (cu > cl)
    {
        cout << txt.upper();
    }
    else
    {
        cout << txt.lower();
    }
    return 0;
}
