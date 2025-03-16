#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

// Function out is used to print the output to the console
void out(vector<string> x) {
    // No need to print in C++ as we use cout
}

// Function nextInt reads an integer from the input
int nextInt() {
    int x;
    cin >> x;
    return x;
}

// Function nextString reads a string from the input
string nextString() {
    string x;
    cin >> x;
    return x;
}

// Define a struct Data to represent a single data point
struct Data {
    string X;
};

// Define a type Datas as a vector of Data
typedef vector<Data> Datas;

// Implement a comparison function for sorting based on X field
bool compare(const Data& a, const Data& b) {
    return a.X < b.X;
}

// Main function starts here
int main() {
    // Read number of data points N from the input
    int N = nextInt();

    // Read number of queries L from the input
    int L = nextInt();

    // Initialize a vector of Data type named s
    Datas s(N);

    // Read data points X from the input and store them in the vector s
    for (int i = 0; i < N; i++) {
        s[i].X = nextString();
    }

    // Print the number of data points N, number of queries L, and the vector s
    out(vector<string>(1, to_string(N) + " " + to_string(L)));
    for (const auto& d : s) {
        out(vector<string>{d.X});
    }

    // Sort the vector s in ascending order based on X field
    sort(s.begin(), s.end(), compare);

    // Initialize an empty string ans to store the concatenated X values
    string ans = "";

    // Iterate through the vector s and concatenate X values to the string ans
    for (const auto& d : s) {
        ans += d.X;
    }

    // Print the concatenated string ans to the console
    cout << ans << endl;

    return 0;
}
