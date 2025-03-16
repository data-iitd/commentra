#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

// Function to compare integers for sorting in descending order
int compare_int(const void *a, const void *b) {
    return *(long int*)b - *(long int*)a; // Sort in descending order
}

// Function to calculate the greatest common divisor
long int gcd(long int a, long int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Function to calculate the least common multiple
long int lcm(long int a, long int b) {
    return a * b / gcd(a, b);
}

int main() {
    long int n;
    long long int k;
    long int q;
    std::vector<long int> a(100001);
    std::vector<long long int> point(100001, 0);

    std::cin >> n >> k >> q;

    // Read the queries and update points
    for (long int i = 0; i < q; i++) {
        std::cin >> a[i];
        point[a[i] - 1]++;
    }

    // Determine if each player has enough points
    for (long int i = 0; i < n; i++) {
        if (k - (q - point[i]) > 0) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }

    return 0;
}

// <END-OF-CODE>
