#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string record_of_movements;
    cin >> record_of_movements;

    int x = 0, y = 0;
    map<string, pair<int, int>> d_movement = {
        {"L", {0, -1}},
        {"R", {0, 1}},
        {"U", {1, 0}},
        {"D", {-1, 0}}
    };
    map<pair<int, int>, string> d = {
        {{x, y}, ""}
    };
    bool bug = false;

    for (auto move : record_of_movements) {
        pair<int, int> temp = {x, y};
        x += d_movement[move].first;
        y += d_movement[move].second;

        if (make_pair(x, y) not in d) {
            for (auto step : d_movement) {
                if (make_pair(x + d_movement[step].first, y + d_movement[step].second)!= temp and make_pair(x + d_movement[step].first, y + d_movement[step].second) in d) {
                    bug = true;
                    break;
                }
            }
        }

        d[make_pair(x, y)] = "";
    }

    if (bug) {
        cout << "BUG" << endl;
    } else {
        cout << "OK" << endl;
    }

    return 0;
}
