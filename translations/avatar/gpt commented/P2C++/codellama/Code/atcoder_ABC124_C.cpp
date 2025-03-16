
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;

    map<char, int> even, odd;

    for (int i = 0; i < s.length(); i += 2)
    {
        even[s[i]]++;
    }

    for (int i = 1; i < s.length(); i += 2)
    {
        odd[s[i]]++;
    }

    int option1 = s.length() - (even['0'] + odd['1']);
    int option2 = s.length() - (even['1'] + odd['0']);

    cout << min(option1, option2) << endl;

    return 0;
}

