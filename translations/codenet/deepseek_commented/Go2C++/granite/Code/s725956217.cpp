
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to print output.
void out(int x) {
    cout << x << endl;
}

// Function to read an integer from input.
int getInt() {
    int x;
    cin >> x;
    return x;
}

// Function to read a string from input.
string getString() {
    string s;
    cin >> s;
    return s;
}

// Function to return the maximum of two integers.
int max(int a, int b) {
    return a > b? a : b;
}

// Function to return the minimum of two integers.
int min(int a, int b) {
    return a < b? a : b;
}

// Function to return the absolute difference between two integers.
int a_sub(int a, int b) {
    return a > b? a - b : b - a;
}

// Function to return the absolute value of an integer.
int abs(int a) {
    return a >= 0? a : -a;
}

// Function to find the lower bound index of a value in a sorted array.
int lower_bound(vector<int> &a, int x) {
    int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
    return idx;
}

// Function to find the upper bound index of a value in a sorted array.
int upper_bound(vector<int> &a, int x) {
    int idx = upper_bound(a.begin(), a.end(), x) - a.begin();
    return idx;
}

// Struct to represent a shop with its price and stock.
struct Shop {
    int a, b;
};

// Vector of shops to implement sorting.
vector<Shop> s;

// Function to compare two shops based on their price.
bool compare(Shop a, Shop b) {
    return a.a < b.a;
}

// Main function to execute the program logic.
int main() {
    // Read the number of shops and the amount of items to buy.
    int N = getInt(), M = getInt();

    // Create a vector of shops and read each shop's price and stock.
    s.resize(N);
    for (int i = 0; i < N; i++) {
        s[i].a = getInt();
        s[i].b = getInt();
    }

    // Sort the shops by price.
    sort(s.begin(), s.end(), compare);

    // Calculate the total cost of buying the required number of items.
    int total = 0;
    for (int i = 0; i < N; i++) {
        // Determine the number of items to buy from the current shop.
        int n = min(s[i].b, M);
        // Update the total cost and the remaining items to buy.
        total += n * s[i].a;
        M -= n;
        // Break if all items are bought.
        if (M == 0) {
            break;
        }
    }

    // Print the total cost.
    out(total);

    return 0;
}

