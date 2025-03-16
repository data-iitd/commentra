#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to read integers from input
int readInt() {
    int num;
    cin >> num;
    return num;
}

// Main function is the entry point of our program
int main() {
    // Read the first three integers A, B, and C from the standard input
    int A = readInt();
    int B = readInt();
    int C = readInt();

    // Check if the difference between B and A is equal to the difference between C and B
    if (B - A == C - B) {
        // If it is, print "YES"
        cout << "YES" << endl;
    } else {
        // Otherwise, print "NO"
        cout << "NO" << endl;
    }

    return 0;
}

// Helper functions for finding the maximum and minimum values
int IntMax(int a, int b) {
    return (a < b) ? b : a;
}

long long Int64Max(long long a, long long b) {
    return (a < b) ? b : a;
}

double Float64Max(double a, double b) {
    return (a < b) ? b : a;
}

int IntMin(int a, int b) {
    return (a > b) ? b : a;
}

long long Int64Min(long long a, long long b) {
    return (a > b) ? b : a;
}

double Float64Min(double a, double b) {
    return (a > b) ? b : a;
}

// Helper function for finding the greatest common divisor of two integers
int IntGcd(int a, int b) {
    return (b == 0) ? a : IntGcd(b, a % b);
}

long long Int64Gcd(long long a, long long b) {
    return (b == 0) ? a : Int64Gcd(b, a % b);
}

// Helper function for finding the absolute value of an integer
int IntAbs(int a) {
    return (a < 0) ? -a : a;
}

long long Int64Abs(long long a) {
    return (a < 0) ? -a : a;
}

// <END-OF-CODE>
