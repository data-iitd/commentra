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
        int power_of_two = 0;
        while (i % 2 == 0)
        {
            power_of_two++;
            i /= 2;
        }

        if (power_of_two > 1)
        {
            cout << 0 << endl;
            return 0;
        }

        two_times_set.insert(power_of_two);
    }

    if (two_times_set.size() != 1)
    {
        cout << 0 << endl;
        return 0;
    }

    int lcm = *num_set.begin();
    for (auto i : num_set)
    {
        lcm = lcm * i / __gcd(lcm, i);
    }

    cout << (num - lcm / 2) / lcm + 1 << endl;

    return 0;
}

