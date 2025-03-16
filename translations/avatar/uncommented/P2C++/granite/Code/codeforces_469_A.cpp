
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int max_level;
    cin >> max_level;
    vector<int> x(max_level);
    vector<int> y(max_level);
    for (int i = 0; i < max_level; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < max_level; i++) {
        cin >> y[i];
    }
    x.erase(remove(x.begin(), x.end(), 0), x.end());
    y.erase(remove(y.begin(), y.end(), 0), y.end());
    set<int> z(x.begin(), x.end());
    z.insert(y.begin(), y.end());
    if (z.size()!= max_level) {
        cout << "Oh, my keyboard!" << endl;
    } else {
        cout << "I become the guy." << endl;
    }
    return 0;
}
