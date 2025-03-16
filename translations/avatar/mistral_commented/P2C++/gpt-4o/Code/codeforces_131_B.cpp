#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    // Read the number of test cases
    int n;
    cin >> n;

    // Initialize a map to store the occurrences of numbers
    unordered_map<int, int> w;

    // Read the numbers and count their occurrences
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        w[num]++;
    }

    // Initialize a counter 'c' to store the result
    long long c = 0;

    // Iterate through each number 'i' in the map 'w'
    for (const auto& pair : w) {
        int i = pair.first;
        // If the number 'i' is zero, then add its occurrences multiplied by (its occurrences - 1) to the counter 'c'
        if (i == 0) {
            c += static_cast<long long>(w[i]) * (w[i] - 1);
        }
        // If the number '-i' is present in the map 'w', then add its occurrences multiplied by the occurrences of 'i' to the counter 'c'
        else if (w.find(-i) != w.end()) {
            c += static_cast<long long>(w[i]) * w[-i];
        }
    }

    // Print the result divided by 2
    cout << c / 2 << endl;

    return 0;
}

// <END-OF-CODE>
