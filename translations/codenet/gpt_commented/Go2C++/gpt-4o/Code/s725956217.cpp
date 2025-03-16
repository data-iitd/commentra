#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to print output to the console.
void out(int x) {
    cout << x << endl;
}

// Structure to represent a shop with a price (a) and available quantity (b).
struct Shop {
    int a, b; // price and quantity
};

// Comparator to sort shops by price.
bool compareShops(const Shop &s1, const Shop &s2) {
    return s1.a < s2.a; // Sort by price (a)
}

int main() {
    int N, M; // Number of shops and total quantity needed
    cin >> N >> M; // Read the number of shops and the total quantity needed

    vector<Shop> shops(N); // Create a vector to hold the shops

    // Read the price and quantity for each shop
    for (int i = 0; i < N; i++) {
        cin >> shops[i].a >> shops[i].b; // Read price (a) and quantity (b)
    }

    sort(shops.begin(), shops.end(), compareShops); // Sort the shops by price

    int total = 0; // Initialize total cost
    // Calculate the total cost based on available quantities and prices
    for (const auto &shop : shops) {
        int n = min(shop.b, M); // Determine how much can be bought from this shop
        total += n * shop.a; // Add to total cost
        M -= n; // Decrease the remaining quantity needed
        if (M == 0) {
            break; // Stop if the required quantity is met
        }
    }

    out(total); // Output the total cost
    return 0;
}

// <END-OF-CODE>
