#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Define the maximum number of time slots
    const int N = 368;

    // Initialize vectors to store changes for males and females
    vector<int> m(N, 0);
    vector<int> f(N, 0);

    // Read the number of operations
    int operations;
    cin >> operations;
    cin.ignore(); // To ignore the newline character after the integer input

    for (int i = 0; i < operations; i++) {
        // Read each line, strip newline, and split into gender, start time, and end time
        string x;
        int a, b;
        getline(cin, x, ' ');
        cin >> a >> b;
        cin.ignore(); // To ignore the newline character after the integer input
        b += 1;

        // Update the changes in the vectors based on gender
        if (x == "M") {
            m[a] += 2;
            m[b] -= 2;
        } else {
            f[a] += 2;
            f[b] -= 2;
        }
    }

    // Initialize variables to store the maximum number of people and the current number of people
    int maleCount = 0, femaleCount = 0, maxPeople = 0;

    // Calculate the cumulative sum of changes and find the maximum number of people at any time slot
    for (int i = 0; i < N; i++) {
        maleCount += m[i];
        femaleCount += f[i];
        if (min(maleCount, femaleCount) > maxPeople) {
            maxPeople = min(maleCount, femaleCount);
        }
    }

    // Print the maximum number of people at any time slot
    cout << maxPeople << endl;

    return 0;
}

// <END-OF-CODE>
