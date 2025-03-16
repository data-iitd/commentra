
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main()
{
    int n, num;
    cin >> n >> num;

    set<int> num_set;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        num_set.insert(temp);
    }

    set<int> two_times_set;
    for (auto i : num_set)
    {
        int j = 1;
        while (i % 2 == 0)
        {
            i /= 2;
            j++;
        }
        if (i % 2 != 0)
        {
            two_times_set.insert(j);
        }
    }

    if (two_times_set.size() != 1)
    {
        cout << 0 << endl;
    }
    else
    {
        int lcm = *num_set.begin();
        for (auto i : num_set)
        {
            lcm = lcm * i / __gcd(lcm, i);
        }
        cout << (num - lcm / 2) / lcm + 1 << endl;
    }

    return 0;
}

