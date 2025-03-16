#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    string record_of_movements;
    cin >> record_of_movements;
    int x = 0, y = 0;
    map<char, pair<int, int>> d_movement;
    d_movement['L'] = make_pair(0, -1);
    d_movement['R'] = make_pair(0, 1);
    d_movement['U'] = make_pair(1, 0);
    d_movement['D'] = make_pair(-1, 0);
    map<pair<int, int>, string> d;
    bool bug = false;
    for (char move : record_of_movements)
    {
        pair<int, int> temp = make_pair(x, y);
        x += d_movement[move].first;
        y += d_movement[move].second;
        if (d.find(make_pair(x, y)) == d.end())
        {
            for (char step : d_movement)
            {
                if (d.find(make_pair(x + d_movement[step].first, y + d_movement[step].second)) != d.end() && make_pair(x + d_movement[step].first, y + d_movement[step].second) != temp)
                {
                    bug = true;
                    break;
                }
            }
        }
        else
        {
            bug = true;
        }
        if (bug)
        {
            break;
        }
        d[make_pair(x, y)] = "";
    }
    if (bug)
    {
        cout << "BUG" << endl;
    }
    else
    {
        cout << "OK" << endl;
    }
    return 0;
}



