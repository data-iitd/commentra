

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create a map to store the counts of integers
    map<int, int> m;
    
    // Read the number of initial elements (N) and the number of operations (M)
    int N, M;
    cin >> N >> M;
    
    // Read N integers and store their counts in the map
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    
    // Perform M operations to update the map with new integers and their counts
    for (int i = 0; i < M; i++) {
        int B, C;
        cin >> B >> C;
        m[C] += B;
    }
    
    // Create a vector of integers from the map keys
    vector<int> ints;
    for (auto& [i, _] : m) {
        ints.push_back(i);
    }
    
    // Sort the vector of integers in descending order
    sort(ints.rbegin(), ints.rend());
    
    // Initialize variables to keep track of the remaining elements and the sum
    int rest = N, sum = 0;
    
    // Iterate through the sorted integers and calculate the sum based on the conditions
    for (int i : ints) {
        int num = m[i];
        if (num >= rest) {
            sum += rest * i;
            break;
        }
        sum += num * i;
        rest -= num;
    }
    
    // Print the calculated sum
    cout << sum << endl;
    
    return 0;
}

// Translate the above C++ code to Java and end with comment "