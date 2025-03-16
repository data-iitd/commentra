#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <utility>

using namespace std;

int main() {
    string record_of_movements;
    cin >> record_of_movements;

    int x = 0, y = 0;
    unordered_map<char, pair<int, int>> d_movement = {
        {'L', {0, -1}},
        {'R', {0, 1}},
        {'U', {1, 0}},
        {'D', {-1, 0}}
    };
    unordered_set<pair<int, int>, hash<pair<int, int>>> d;
    d.insert({x, y});
    bool bug = false;

    for (char move : record_of_movements) {
        pair<int, int> temp = {x, y};
        x += d_movement[move].first;
        y += d_movement[move].second;

        if (d.find({x, y}) == d.end()) {
            for (auto& step : d_movement) {
                if ((x + step.second.first != temp.first || y + step.second.second != temp.second) && d.find({x + step.second.first, y + step.second.second}) != d.end()) {
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

        d.insert({x, y});
    }

    if (bug) {
        cout << "BUG" << endl;
    } else {
        cout << "OK" << endl;
    }

    return 0;
}

