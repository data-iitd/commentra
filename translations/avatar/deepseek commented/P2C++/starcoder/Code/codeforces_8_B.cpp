
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string record_of_movements;
    cin >> record_of_movements;
    int x = 0, y = 0;
    map<char, pair<int, int>> d_movement = {{'L', {0, -1}}, {'R', {0, 1}}, {'U', {1, 0}}, {'D', {-1, 0}}};
    map<pair<int, int>, string> d = {{make_pair(x, y), ""}};
    bool bug = false;
    
    for (char move : record_of_movements) {
        pair<int, int> temp = make_pair(x, y);
        x += d_movement[move].first;
        y += d_movement[move].second;
        
        if (make_pair(x, y) not in d) {
            for (auto step : d_movement) {
                if (make_pair(x + d_movement[step].first, y + d_movement[step].second)!= temp and make_pair(x + d_movement[step].first, y + d_movement[step].second) in d) {
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

