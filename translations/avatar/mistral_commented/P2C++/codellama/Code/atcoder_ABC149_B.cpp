#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Define a list 'cookies' by using list comprehension
    vector<int> cookies;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int cookie;
    while (ss >> cookie) {
        cookies.push_back(cookie);
    }

    // Calculate the difference between the number of cookies given to the first and second child
    int leftOver = cookies[0] - cookies[2];

    // Set the 'takahashi' variable to the maximum value between 0 and the 'leftOver' variable
    int takahashi = max(0, leftOver);

    // Print the result using string concatenation
    cout << takahashi << ' ' << (takahashi > 0 ? cookies[1] : max(0, cookies[1] - abs(leftOver)));

    return 0;
}

