#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read an integer
int readInt() {
    int x;
    cin >> x;
    return x;
}

// Function to read multiple integers
vector<int> readInts() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> ints;
    int num;
    while (ss >> num) {
        ints.push_back(num);
    }
    return ints;
}

// Main function
void main() {
    // Setting the modulus value
    const long long mod = 1000000007;

    // Reading input values: N, A, and B
    vector<int> inputs = readInts();
    int N = inputs[0];
    int A = inputs[1];
    int B = inputs[2];

    // Initializing the answer variable to 0
    long long ans = 0;

    // Calculating the number of repetitions
    int rep = N / (A + B);

    // Adding the number of blocks that can be fully covered by A and B in one repetition
    ans += rep * A;

    // Calculating the remaining number of blocks
    int res = N - rep * (A + B);

    // Adding the number of blocks that can be covered by A in the remaining blocks
    ans += min(res, A);

    // Printing the final answer
    cout << ans << endl;
}

