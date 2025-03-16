#######
#include <iostream>
#include <vector>
using namespace std;

// This is the main function that is called when we run the script.
// It takes an input of an integer N and a list P of N integers as arguments.
// It then calls the editorial function with these arguments.
int main() {
    // Read the number of test cases N from the standard input.
    int N;
    cin >> N;
    // Read N integers from the standard input and store them in a list P.
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    // Call the editorial function with N and P as arguments.
    editorial(N, P);
    return 0;
}

// This function calculates the answer based on the given input.
void editorial(int N, vector<int> P) {
    // Base case: if there is only one element in the list, the answer is 0.
    if (N == 1) {
        cout << 0 << endl;
        return;
    }
    // Initialize an array a of size N+1 with all elements initialized to 0.
    vector<int> a(N + 1, 0);
    // Iterate through the list P and assign each element its index in the array a.
    for (int i = 0; i < N; i++) {
        a[P[i]] = i;
    }
    // Initialize two variables: tmp to keep track of the current streak,
    // and max_len to keep track of the maximum streak.
    int tmp = 1;
    int max_len = 1;
    // Iterate through the array a from the second element to the last.
    for (int i = 1; i < N; i++) {
        // If the current element has a smaller index than the previous one,
        // increment the streak and update max_len if necessary.
        if (a[i] < a[i + 1]) {
            tmp += 1;
            max_len = max(max_len, tmp);
        }
        // Otherwise, reset the streak to 1.
        else {
            tmp = 1;
        }
    }
    // Calculate the answer as the difference between the total number of elements
    // and the maximum streak.
    int ans = N - max_len;
    // Print the answer.
    cout << ans << endl;
}

// This function is used for testing purposes and is not called in the main function.
void WA(int N, vector<int> P) {
    // Initialize two variables: tmp to keep track of the current streak,
    // and ans to keep track of the maximum answer.
    int tmp = 0;
    int ans = 0;
    // Iterate through the list P and calculate the answer based on the current streak.
    for (int i = 0; i < N; i++) {
        // If the current element is the first one or its previous element plus one,
        // increment the streak and update ans if necessary.
        if (i == 0 || P[i - 1] + 1 == P[i]) {
            tmp += 1;
            ans = max(ans, tmp);
        }
        // Otherwise, reset the streak to 1.
        else {
            tmp = 1;
        }
    }
    // Print the answer.
    cout << N - ans << endl;
}

// This line is executed only if the script is run as the main module, not imported as a module.
// 