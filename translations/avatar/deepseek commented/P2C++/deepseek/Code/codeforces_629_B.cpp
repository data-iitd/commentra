#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Define the maximum number of time slots
    const int N = 368;

    // Initialize vectors to store changes for males and females
    vector<int> m(N, 0);
    vector<int> f(N, 0);

    // Read the number of operations
    int num_operations;
    cin >> num_operations;
    cin.ignore(); // Ignore the newline character

    for (int i = 0; i < num_operations; ++i) {
        // Read each line, strip newline, and split into gender, start time, and end time
        string line;
        getline(cin, line);
        char gender = line[0];
        int start_time = stoi(line.substr(2, 2));
        int end_time = stoi(line.substr(5, 2)) + 1;

        // Update the changes in the vectors based on gender
        if (gender == 'M') {
            m[start_time] += 2;
            m[end_time] -= 2;
        } else {
            f[start_time] += 2;
            f[end_time] -= 2;
        }
    }

    // Initialize variables to store the maximum number of people and the current number of people
    int a = 0, b = 0, c = 0;

    // Calculate the cumulative sum of changes and find the maximum number of people at any time slot
    for (int i = 0; i < N; ++i) {
        a += m[i];
        b += f[i];
        c = max(c, min(a, b));
    }

    // Print the maximum number of people at any time slot
    cout << c << '\n';

    return 0;
}
