
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read the number of elements in the list
    int n; cin >> n;

    // Read the list of integers and count the occurrences of each integer
    map<int, int> w;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        w[x]++;
    }

    // Initialize a variable to store the count of pairs
    int c = 0;

    // Iterate over each integer in the map
    for (auto i : w) {
        // If the integer is 0, calculate the number of ways to choose 2 items from the occurrences of 0
        if (i.first == 0) {
            c += w[i.first] * (w[i.first] - 1);
        }
        // If the integer is not 0, check if its negative counterpart is also in the map
        else {
            if (-i.first in w) {
                // Calculate the number of ways to choose 2 items from the occurrences of i and -i
                c += w[i.first] * w[-i.first];
            }
        }
    }

    // Print the result of c // 2, which represents the number of unique pairs
    cout << c / 2 << endl;

    return 0;
}

