#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;

    int A = max(H, W);
    cout << (N + A - 1) / A << endl;

    return 0;
}

// Scanner class is not needed in this simple case as we can use cin directly.
// If needed, we could implement a custom scanner class similar to the Go version.

