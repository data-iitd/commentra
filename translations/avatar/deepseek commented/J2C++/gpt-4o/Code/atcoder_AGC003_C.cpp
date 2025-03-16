#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

const int NUM = 1e5 + 2;

int main() {
    // Initialize a variable to read the number of elements
    int N;
    cin >> N;

    // Initialize an unordered_map to store value and its index
    unordered_map<int, int> map;

    // Initialize a priority_queue to store numbers
    priority_queue<int, vector<int>, greater<int>> nums;

    // Read each number, add it to the priority_queue, and store its value and index in the unordered_map
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        nums.push(tmp);
        map[tmp] = i;
    }

    // Initialize variables to keep track of the current index and the count of differences
    int bin = 0;
    int diff = 0;

    // Loop until the priority_queue is empty
    while (!nums.empty()) {
        // Retrieve the next number and its index from the priority_queue and unordered_map
        int num = nums.top();
        nums.pop();
        int idx = map[num];

        // If the current index is not even when bin is even (or vice versa), increment the diff counter
        if ((bin % 2) != (idx % 2)) {
            diff++;
        }

        // Update bin and take modulo 2 to keep it within 0 or 1
        bin++;
        bin %= 2;
    }

    // Calculate the answer by dividing diff by 2
    int ans = diff / 2;

    // Print the result
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
