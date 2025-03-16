#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // Read the number of elements in the list
    int n;
    cin >> n;

    // Read the list of integers and count the occurrences of each integer
    unordered_map<int, int> w;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        w[x]++;
    }

    // Initialize a variable to store the count of pairs
    long long c = 0;

    // Iterate over each integer in the unordered_map
    for (const auto& pair : w) {
        int i = pair.first;
        // If the integer is 0, calculate the number of ways to choose 2 items from the occurrences of 0
        if (i == 0) {
            c += (long long)w[i] * (w[i] - 1);
        } 
        // If the integer is not 0, check if its negative counterpart is also in the unordered_map
        else {
            if (w.find(-i) != w.end()) {
                // Calculate the number of ways to choose 2 items from the occurrences of i and -i
                c += (long long)w[i] * w[-i];
            }
        }
    }

    // Print the result of c / 2, which represents the number of unique pairs
    cout << c / 2 << endl;

    return 0;
}

// <END-OF-CODE>
