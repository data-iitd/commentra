#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

#define MAX 707106 // sqrt(10^12/2)

std::vector<char> tbl(MAX + 1);
int sz; // max sz = 57084, prime[0] = 2, prime[57083] = 707099
std::vector<int> prime(57100); // Declare a vector to store prime numbers

void sieve() {
    int i, j, k;

    // Sieve of Eratosthenes algorithm to find prime numbers up to sqrt(MAX)
    for (i = 1; i < 147; i++) {
        k = prime[i]; // Get the current prime number
        for (j = k * k; j < MAX; j += k) tbl[j] = 1; // Mark all multiples of 'k' as composite in 'tbl' array
    }
    // Find all prime numbers greater than sqrt(MAX)
    for (sz = 146, i = 853; i <= MAX; i += 2)
        if (!tbl[i]) prime[sz++] = i; // If 'i' is not marked as composite, it is a prime number
}

std::vector<int> base(1000002);
std::vector<int> idx(1000002);
long long pp[41]; // 2^40 = 1099511627776 >= 10^12

int bsch(int x) {
    int m, l = 0, r = sz;

    // Binary search algorithm to find the index of the largest prime number 'p' such that 'p^2 <= x'
    while (l < r) {
        m = (l + r) >> 1; // Calculate the middle index 'm'
        if (prime[m] == x) return m; // If 'x' is a prime number, return its index
        if (prime[m] < x) l = m + 1; // If 'prime[m]' is smaller than 'x', 'l' should be updated
        else r = m; // Otherwise, 'r' should be updated
    }
    return l - 1; // Return the index of the largest prime number 'p' such that 'p^2 <= x'
}

int main() {
    int i, k, p, ans;
    long long A, B, a, b, j, ll, rr;

    sieve(); // Call the Sieve of Eratosthenes algorithm to find prime numbers

    std::cin >> A >> B; // Read two integers 'A' and 'B' from the standard input
    a = A - B, b = A + B; // Calculate 'a' = 'A' - 'B' and 'b' = 'A' + 'B'
    if (b <= 1) { std::cout << "0\n"; return 0; } // If 'b' is less than or equal to 1, output '0' and terminate the program
    if (a <= 1) a = 2; // If 'a' is less than or equal to 1, set it to 2

    sz = bsch(static_cast<int>(sqrt(static_cast<double>(b >> 1)))); // Find the largest prime number 'p' such that 'p^2 <= b' using binary search

    std::memset(idx.data(), 1, sizeof(int) * idx.size()); // Initialize all elements of 'idx' array to 1
    std::memset(base.data(), 0, sizeof(int) * base.size()); // Initialize all elements of 'base' array to 0

    for (i = 0; i <= sz; i++) {
        p = prime[i]; // Get the current prime number
        for (k = 1, j = p; j <= b; j *= p) pp[k++] = j; // Calculate all powers of 'p' less than or equal to 'b'
        for (; k--; ) {
            j = pp[k], ll = j * (1 + (a - 1) / j), rr = j * (b / j); // Calculate the lower and upper bounds of the segment to search for 'a' in
            for (; ll <= rr; ll += j) {
                int x = static_cast<int>(ll - a); // Calculate the index 'x' of the segment
                if (!idx[x] || base[x] == p) continue; // If 'x' is already processed or the prime number at 'x' is the same as 'p', skip it
                base[x] = p, idx[x] = k; // Otherwise, set the prime number at 'x' to 'p' and its index to 'k'
            }
        }
    }

    ans = 0, i = static_cast<int>(b - a + 1); // Initialize 'ans' to 0 and the loop counter 'i' to the number of segments
    while (i--) if (idx[i]) ans++; // Increment 'ans' if the current segment has been processed
    std::cout << ans << "\n"; // Output the result 'ans' and terminate the program
    return 0;
}

// <END-OF-CODE>
