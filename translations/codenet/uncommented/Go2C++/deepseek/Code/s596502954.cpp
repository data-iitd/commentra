#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int nextInt() {
    int value;
    cin >> value;
    return value;
}

vector<int> nextInts(int n) {
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    return values;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int a = nextInt();
    int b = nextInt();
    int c = nextInt();

    if (a + b >= c) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
