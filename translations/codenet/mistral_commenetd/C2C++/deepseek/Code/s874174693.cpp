#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

// Function to swap two integers
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to find the greatest common divisor (GCD) of two numbers
long int gcd(long int a, long int b) {
    long int c;
    while (b > 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

// Comparator function for sort() to sort in ascending order
bool upll(const ll& a, const ll& b) {
    return a < b;
}

// Comparator function for sort() to sort in descending order
bool downll(const ll& a, const ll& b) {
    return a > b;
}

// Function to sort a vector in ascending order using sort()
void sortup(std::vector<ll>& a) {
    std::sort(a.begin(), a.end(), upll);
}

// Function to sort a vector in descending order using sort()
void sortdown(std::vector<ll>& a) {
    std::sort(a.begin(), a.end(), downll);
}

// Function to calculate a^n modulo m
long int modpow(long int a, long int n, long int mod) {
    long int ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        n /= 2;
    }
    return ans;
}

// Function to find the modular multiplicative inverse of a modulo m
long int modinv(long int a, long int mod) {
    return modpow(a, mod - 2, mod);
}

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a < b) ? b : a;
}

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to update the value of a variable with the maximum of the current value and a new value
void chmax(int* a, int b) {
    if (*a < b) {
        *a = b;
    }
}

// Function to update the value of a variable with the minimum of the current value and a new value
void chmin(int* a, int b) {
    if (*a > b) {
        *a = b;
    }
}

// Main function
int main(void) {
    int n;
    int sum = 0;
    int m;

    std::cin >> n;
    m = n;

    while (m > 0) {
        sum += m % 10;
        m /= 10;
    }

    if (n % sum == 0) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}

