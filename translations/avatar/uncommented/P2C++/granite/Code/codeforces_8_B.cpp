
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string record_of_movements;
    cin >> record_of_movements;
    int x = 0, y = 0;
    map<pair<int, int>, string> d_movement = { {'L', make_pair(0, -1)}, {'R', make_pair(0, 1)}, {'U', make_pair(1, 0)}, {'D', make_pair(-1, 0)} };
    map<pair<int, int>, string> d = { {make_pair(x, y), ""} };
    bool bug = false;
    for (char move : record_of_movements) {
        pair<int, int> temp = make_pair(x, y);
        x += d_movement[move][0];
        y += d_movement[move][1];
        if (d.find(make_pair(x, y)) == d.end()) {
            for (auto step : d_movement) {
                if (make_pair(x + step.second[0], y + step.second[1])!= temp && d.find(make_pair(x + step.second[0], y + step.second[1]))!= d.end()) {
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
        d[make_pair(x, y)] = "";
    }
    if (bug) {
        cout << "BUG" << endl;
    } else {
        cout << "OK" << endl;
    }
    return 0;
}
