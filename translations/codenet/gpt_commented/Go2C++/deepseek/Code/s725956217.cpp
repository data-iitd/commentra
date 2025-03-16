#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// shop represents a shop with a price (a) and available quantity (b).
struct shop {
    int a, b;
};

// Datas is a vector of shop.
using Datas = vector<shop>;

// Compare function for sorting shops by price.
bool compare(const shop& lhs, const shop& rhs) {
    return lhs.a < rhs.a;
}

int main() {
    int N, M;
    cin >> N >> M;
    Datas s(N);

    // Read the price and quantity for each shop
    for (int i = 0; i < N; ++i) {
        cin >> s[i].a >> s[i].b;
    }
    sort(s.begin(), s.end(), compare); // Sort the shops by price

    int total = 0; // Initialize total cost
    // Calculate the total cost based on available quantities and prices
    for (const auto& e : s) {
        int n = min(e.b, M); // Determine how much can be bought from this shop
        total += n * e.a; // Add to total cost
        M -= n; // Decrease the remaining quantity needed
        if (M == 0) {
            break; // Stop if the required quantity is met
        }
    }
    cout << total << endl; // Output the total cost

    return 0;
}
