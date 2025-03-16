
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string str;
    cin >> n;
    cin.ignore();
    getline(cin, str);
    string a = "";
    string b = "";
    for (int i = 0; i < n / 2; i++)
    {
        a = a + str[i];
    }
    if (str.compare(a + a) == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}

