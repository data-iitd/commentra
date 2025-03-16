#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Read a line of input, split it into parts, and convert each part to an integer
    vector<int> cookies;
    string line;
    getline(cin, line);
    for (string part : line.split(" ")) {
        cookies.push_back(stoi(part));
    }

    // Calculate the leftover cookies after taking some from the third type
    int leftOver = cookies[0] - cookies[2];

    // Determine the number of cookies Takahashi can take, ensuring it's not negative
    int takahashi = max(0, leftOver);

    // Print the number of cookies Takahashi can take, and the remaining cookies of the second type
    // If Takahashi can take cookies, print the second type's count; otherwise, calculate the remaining
    cout << takahashi << " " << (cookies[1] if takahashi > 0 else max(0, cookies[1] - abs(leftOver))) << endl;

    return 0;
}

