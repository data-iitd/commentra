#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read the input
    vector<int> cookies;
    int cookie;
    while (cin >> cookie) {
        cookies.push_back(cookie);
    }

    // Calculate the difference between the number of cookies given to the first and second child
    int leftOver = cookies[0] - cookies[2];

    // Set the 'takahashi' variable to the maximum value between 0 and the 'leftOver' variable
    int takahashi = max(0, leftOver);

    // Print the result
    cout << takahashi <<'' << (cookies[1] if takahashi > 0 else max(0, cookies[1] - abs(leftOver))) << endl;

    return 0;
}
