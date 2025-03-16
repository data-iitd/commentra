#include <iostream>
#include <set>
using namespace std;

int main() {
    int max_level, x, y;
    cin >> max_level >> x >> y;
    set<int> X, Y;
    for (int i = 0; i < x; i++) {
        int temp;
        cin >> temp;
        X.insert(temp);
    }
    for (int i = 0; i < y; i++) {
        int temp;
        cin >> temp;
        Y.insert(temp);
    }
    if (X.count(0) || Y.count(0)) {
        cout << "Oh, my keyboard!" << endl;
    } else {
        cout << "I become the guy." << endl;
    }
    return 0;
}
