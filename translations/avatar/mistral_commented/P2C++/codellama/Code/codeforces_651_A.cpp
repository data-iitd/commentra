
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    // Calculate and print the maximum value between x + y - 3 + ( ( y - x ) % 3 > 0 ) and 0
    cout << max(x + y - 3 + ( ( y - x ) % 3 > 0 ), 0) << endl;

    return 0;
}

