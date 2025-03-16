
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string record_of_movements;
    cin >> record_of_movements;
    int x = 0, y = 0;
    map<char, pair<int, int>> d_movement = {
        {'L', make_pair(0, -1)},
        {'R', make_pair(0, 1)},
        {'U', make_pair(1, 0)},
        {'D', make_pair(-1, 0)}
    };
    map<pair<int, int>, char> d = {
        {make_pair(x, y), ''}
    };
    bool bug = false;

    for (char move : record_of_movements) {
        pair<int, int> temp = make_pair(x, y);
        x += d_movement[move].first;
        y += d_movement[move].second;

        if (d.find(make_pair(x, y)) == d.end()) {
            for (char step : d_movement) {
                if (make_pair(x + d_movement[step].first, y + d_movement[step].second) != temp && d.find(make_pair(x + d_movement[step].first, y + d_movement[step].second)) != d.end()) {
                    bug = true;
                    break;
                }
            }
        } else {
            bug = true;
        }

        if (bug) {
            break;
        }

        d[make_pair(x, y)] = '';
    }

    if (bug) {
        cout << "BUG" << endl;
    } else {
        cout << "OK" << endl;
    }

    return 0;
}

