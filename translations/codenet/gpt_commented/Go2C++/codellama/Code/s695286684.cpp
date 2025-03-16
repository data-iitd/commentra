
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    cout << s.replace(s.find("2017"), 4, "2018") << endl;
    return 0;
}

