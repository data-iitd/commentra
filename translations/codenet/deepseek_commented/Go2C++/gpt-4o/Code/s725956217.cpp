#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Struct to represent a shop with its price and stock.
struct Shop {
    int price, stock;
};

// Function to read an integer from input.
int getInt() {
    int x;
    cin >> x;
    return x;
}

// Main function to execute the program logic.
int main() {
    // Read the number of shops and the amount of items to buy.
    int N = getInt(), M = getInt();

    // Create a vector of shops and read each shop's price and stock.
    vector<Shop> shops(N);
    for (int i = 0; i < N; i++) {
        shops[i].price = getInt();
        shops[i].stock = getInt();
    }

    // Sort the shops by price.
    sort(shops.begin(), shops.end(), [](const Shop &a, const Shop &b) {
        return a.price < b.price;
    });

    // Calculate the total cost of buying the required number of items.
    int total = 0;
    for (const auto &shop : shops) {
        // Determine the number of items to buy from the current shop.
        int n = min(shop.stock, M);
        // Update the total cost and the remaining items to buy.
        total += n * shop.price;
        M -= n;
        // Break if all items are bought.
        if (M == 0) {
            break;
        }
    }

    // Print the total cost.
    cout << total << endl;

    return 0;
}

// <END-OF-CODE>
