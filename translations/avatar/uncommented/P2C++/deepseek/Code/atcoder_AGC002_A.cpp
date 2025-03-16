#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <functional>
#include <sstream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a > 0) {
        cout << "Positive" << endl;
    } else if (a <= 0 && b >= 0) {
        cout << "Zero" << endl;
    } else {
        if ((a + b) % 2 == 0) {
            cout << "Negative" << endl;
        } else {
            cout << "Positive" << endl;
        }
    }
    return 0;
}

