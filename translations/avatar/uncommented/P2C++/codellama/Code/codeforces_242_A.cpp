
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    vector<pair<int, int>> games;
    for (int i = a; i <= x; i++)
    {
        if (i <= b)
            continue;
        else
        {
            for (int j = b; j <= y; j++)
            {
                if (i > j)
                    games.push_back(make_pair(i, j));
            }
        }
    }
    cout << games.size() << endl;
    for (auto i : games)
        cout << i.first << " " << i.second << endl;
    return 0;
}

