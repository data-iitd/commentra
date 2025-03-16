// Include necessary headers
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

// Use the standard namespace
using namespace std;

// Function to read an integer from standard input
int getInt() {
    int i;
    cin >> i;
    return i;
}

// Function to print output to the console
void out(int x) {
    cout << x << endl;
}

// Structure to represent a shop with capacity and demand
struct Shop {
    int a, b; // a: capacity, b: demand
};

// Comparison function for sorting shops based on capacity
bool compareShops(const Shop &s1, const Shop &s2) {
    return s1.a < s2.a;
}

// Main function is the entry point of the program
int main() {
    // Read the number of shops N and the number of customers M from standard input
    int N = getInt(), M = getInt();
    
    // Initialize a vector of shops
    vector<Shop> shops(N);
    
    // For each shop, read its capacity and demand
    for (int i = 0; i < N; i++) {
        int a = getInt(), b = getInt();
        shops[i] = {a, b}; // Create a new shop with the read values
    }
    
    // Sort the shops in ascending order based on capacity
    sort(shops.begin(), shops.end(), compareShops);
    
    // Initialize a variable to store the total capacity used by the shops
    int total = 0;
    
    // For each shop in the sorted vector
    for (const auto &e : shops) {
        // Calculate the minimum capacity that can be served by the shop without exceeding the maximum demand
        int n = min(e.b, M);
        // Add the capacity of the shop multiplied by the number of customers it can serve to the total capacity
        total += n * e.a;
        // Decrease the maximum demand by the number of customers served by the shop
        M -= n;
        // If the maximum demand becomes zero, break the loop
        if (M == 0) {
            break;
        }
    }
    
    // Print the total capacity used by the shops
    out(total);
    
    return 0; // Return success
}

// <END-OF-CODE>
