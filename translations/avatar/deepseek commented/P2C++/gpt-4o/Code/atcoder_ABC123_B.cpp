#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    vector<pair<int, int>> menu; // Vector to store pairs of input values and processed last digits
    for (int i = 0; i < 5; ++i) {
        string m;
        cin >> m; // Taking input from the user
        int e = m.back() - '0'; // Extracting the last digit and converting it to an integer
        if (e == 0) {
            e = 10; // If the last digit is 0, change it to 10
        }
        menu.push_back({stoi(m), e}); // Appending the input value and the processed last digit as a pair to the menu vector
    }

    // Sorting the menu vector based on the last digit
    sort(menu.begin(), menu.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int ans = 0;
    for (size_t i = 1; i < menu.size(); ++i) {
        ans += ceil(static_cast<double>(menu[i].first) / 10) * 10; // Calculating the sum
    }

    cout << ans + menu[0].first << endl; // Printing the sum of the first element and the calculated ans
    return 0;
}

// <END-OF-CODE>
