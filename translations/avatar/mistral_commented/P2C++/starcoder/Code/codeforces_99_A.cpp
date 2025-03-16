#include <iostream>
#include <string>
using namespace std;

int main()
{
    string l;
    cin >> l;
    l = l.substr(0, l.find('.'));
    l = l.substr(l.find('.') + 1);
    string s = l.substr(0, 1);
    string p = l.substr(2, 1);
    if (s[0] == '9')
    {
        cout << "GOTO Vasilisa." << endl;
    }
    else if (s[0]!= '9' && p[0] < 5)
    {
        cout << s << endl;
    }
    else
    {
        s[0]++;
        cout << s << endl;
    }
    return 0;
}

