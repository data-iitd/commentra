
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

    int min_flips = INT_MAX;

    for (auto it : even)
    {
        int flips = s.length() - (it.second + odd[it.first]);
        min_flips = min(min_flips, flips);
    }

    for (auto it : odd)
    {
        int flips = s.length() - (it.second + even[it.first]);
        min_flips = min(min_flips, flips);
    }

    cout << min_flips << endl;

    return 0;
}

