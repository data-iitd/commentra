#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Define constant value
const int MOD = 1000000007;

// Define function to calculate factorial
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1) % MOD;
}

// Define function to calculate inverse
int inverse(int n) {
    return pow(n + 1, MOD - 2, MOD);
}

// Define function to calculate cumulative sum
vector<int> cumulative_sum(vector<int> arr) {
    vector<int> result(arr.size());
    result[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        result[i] = (result[i - 1] + arr[i]) % MOD;
    }
    return result;
}

// Define function to calculate temporary array
vector<int> temporary_array(vector<int> arr) {
    vector<int> result(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        result[i] = (inverse(i + 1) + inverse(arr.size() - i - 1) - 1) % MOD;
    }
    return result;
}

// Define function to calculate the answer
int calculate_answer(vector<int> arr) {
    vector<int> inv = cumulative_sum(vector<int>(arr.size(), 1));
    for (int i = 1; i < arr.size(); i++) {
        inv[i] = (inv[i - 1] + inv[i]) % MOD;
    }
    vector<int> temp = temporary_array(arr);
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        ans = (ans + (arr[i] * temp[i]) % MOD) % MOD;
    }
    return ans;
}

// Define main function
int main() {
    // Read input number of elements N
    int N;
    cin >> N;

    // Define a constant value for the size of the 1D array A
    const int M = 1000000;

    // Initialize 1D NumPy array A with given size and input data
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Calculate the answer ans using given formula
    int ans = calculate_answer(A);

    // Modulo the answer ans with given constant value MOD
    ans %= MOD;

    // Print the answer ans
    cout << ans << endl;

    return 0;
}

