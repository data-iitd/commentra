#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    int high = 1;
    int tower = n;
    for (int i = 1; i < n; i++) {
        if (l[i] == l[i-1]) {
            tower--;
            high++;
        } else {
            if (high > tower) {
                tower = high;
            }
            high = 1;
        }
    }
    if (high > tower) {
        tower = high;
    }
    cout << tower << " " << tower - 1 << endl;
    return 0;
}
