
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    // Read the number of players (n) and the number of levels (levels)
    int n, levels;
    cin >> n >> levels;

    // Initialize variables to keep track of sums and counts
    int sum = 0, sum2 = 0, sum3 = 0;

    // Create an array to store the levels completed by the first player
    vector<int> arr(levels);

    // Read the levels completed by the first player
    for (int i = 0; i < levels; i++) {
        cin >> arr[i];
    }

    // Read the number of additional levels completed by the second player
    int level2;
    cin >> level2;

    // Calculate the total number of levels completed by both players
    int level3 = levels + level2;

    // Create a new array to store levels completed by both players
    vector<int> arr2(level3);

    // Copy levels from the first player's array to the new array
    for (int i = 0; i < arr.size(); i++) {
        arr2[i] = arr[i];
    }

    // Read the levels completed by the second player and add them to the new array
    for (int i = arr.size(); i < level3; i++) {
        cin >> arr2[i];
    }

    // Create an array to represent all levels (1 to n)
    vector<int> arr3(n);

    // Fill arr3 with level numbers from 1 to n
    for (int i = 0; i < n; i++) {
        arr3[i] = i + 1;
    }

    // Check how many levels from arr3 are completed by either player
    int count = 0;
    for (int i = 0; i < arr3.size(); i++) {
        for (int x = 0; x < arr2.size(); x++) {
            // If a level is found in arr2, increment the count and break
            if (arr3[i] == arr2[x]) {
                count++;
                break;
            }
        }
    }

    // Determine if all levels have been completed by at least one player
    if (count == n) {
        cout << "I become the guy." << endl;
    } else {
        cout << "Oh, my keyboard!" << endl;
    }

    return 0;
}
