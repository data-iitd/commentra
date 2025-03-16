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

    for (int i = 0; i < s.length() / 2; i++)
    {
        even[s[i]]++;
    }

    for (int i = s.length() / 2; i < s.length(); i++)
    {
        odd[s[i]]++;
    }

    int min_diff = INT_MAX;

    for (auto it : even)
    {
        min_diff = min(min_diff, s.length() - (it.second + odd['1']));
    }

    for (auto it : odd)
    {
        min_diff = min(min_diff, s.length() - (it.second + even['0']));
    }

    cout << min_diff << endl;

    return 0;
}

