#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for dynamic arrays

using namespace std; // Using the standard namespace

int main() { // Starting the main function
    string S; // Declaring a string to store input
    cin >> S; // Reading the first line of input as a string
    int N = S.length(); // Getting the length of the string

    vector<int> mod_arr(N); // Creating a vector of size N to store intermediate results
    vector<int> mod_cnt(2019, 0); // Creating a vector of size 2019 to count the frequency of each number
    int radix = 1; // Initializing the radix to 1

    for (int i = 0; i < N; i++) { // Iterating through each character in the string
        int tmp = 0; // Initializing a temporary variable to store the intermediate result

        // Calculating the value of the current digit in the given base
        tmp = (S[N - 1 - i] - '0') * radix % 2019;

        // Updating the temporary variable with the carry from the previous digit
        if (i != 0) tmp = (tmp + mod_arr[i - 1]) % 2019;

        // Storing the intermediate result in the vector
        mod_arr[i] = tmp;

        // Updating the frequency count of the current number in the vector
        mod_cnt[tmp]++;

        // Updating the radix for the next iteration
        radix = radix * 10 % 2019;
    }

    long long ans = 0LL; // Initializing a long long variable to store the final answer

    // Calculating the answer by summing up the terms of the formula
    for (int i = 0; i < 2019; i++) {
        ans += mod_cnt[i] * (mod_cnt[i] - 1) / 2;
    }

    cout << ans << endl; // Printing the final answer
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
