#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int c = 0;
    for (int i = 0; i < n; i++) {
        vector<int> l1;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            l1.push_back(x);
        }
        if (accumulate(l1.begin(), l1.end(), 0) > 1) {
            c++;
        }
    }
    cout << c << endl;
    return 0;
}

