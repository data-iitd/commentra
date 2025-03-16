#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to read an integer from the input
int nextInt() {
    int x;
    cin >> x;
    return x;
}

// Function to read a string from the input
string nextString() {
    string x;
    cin >> x;
    return x;
}

// Define a struct Data to represent a single data point
struct Data {
    string X;
};

// Comparator function to sort Data based on the X field
bool compareData(const Data &a, const Data &b) {
    return a.X < b.X;
}

// Main function starts here
int main() {
    // Read number of data points N from the input
    int N = nextInt();

    // Read number of queries L from the input
    int L = nextInt();

    // Initialize a vector of Data type named s
    vector<Data> s(N);

    // Read data points X from the input and store them in the vector s
    for (int i = 0; i < N; i++) {
        s[i].X = nextString();
    }

    // Print the number of data points N, number of queries L, and the vector s
    // Note: The output is commented out as per the original Go code
    // cout << N << " " << L << " ";
    // for (const auto& data : s) {
    //     cout << data.X << " ";
    // }
    // cout << endl;

    // Sort the vector s in ascending order based on X field
    sort(s.begin(), s.end(), compareData);

    // Initialize an empty string ans to store the concatenated X values
    string ans = "";

    // Iterate through the vector s and concatenate X values to the string ans
    for (int i = 0; i < N; i++) {
        ans += s[i].X;
    }

    // Print the concatenated string ans to the console
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
