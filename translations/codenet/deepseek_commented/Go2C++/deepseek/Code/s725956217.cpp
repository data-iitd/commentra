#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to print output.
void out(long long x) {
    cout << x << endl;
}

// Function to return the maximum of two integers.
int max(int a, int b) {
    return a > b ? a : b;
}

// Function to return the minimum of two integers.
int min(int a, int b) {
    return a < b ? a : b;
}

// Struct to represent a shop with its price and stock.
struct shop {
    int a, b;
};

// Vector of shops to implement sorting.
typedef vector<shop> Datas;

// Implementing sort.Interface for Datas.
bool operator<(const shop& lhs, const shop& rhs) {
    return lhs.a < rhs.a;
}

int main() {
    int N, M;
    cin >> N >> M;

    // Create a vector of shops and read each shop's price and stock.
    Datas s(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i].a >> s[i].b;
    }

    // Sort the shops by price.
    sort(s.begin(), s.end());

    // Calculate the total cost of buying the required number of items.
    long long total = 0;
    for (const auto& e : s) {
        // Determine the number of items to buy from the current shop.
        int n = min(e.b, M);
        // Update the total cost and the remaining items to buy.
        total += static_cast<long long>(n) * e.a;
        M -= n;
        // Break if all items are bought.
        if (M == 0) {
            break;
        }
    }

    // Print the total cost.
    out(total);

