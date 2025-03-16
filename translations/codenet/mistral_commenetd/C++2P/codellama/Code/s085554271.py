#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
#include <iterator>
#include <map>
#include <fstream>
//#include <list>
#include <iomanip>
//#include <stdlib.h>
//#include <cctype>

using namespace std;

#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); // Initialize I/O streams
#define prec std::cout << std::fixed << std::setprecision(15); // Set precision for floating point numbers
#define endl "\n"
#define MOD 1000000007 // Define constant for modulo arithmetic
#define Int int64_t // Define long integer type
#define PI 3.14159265358979 // Define constant for pi
#define ssort(z) sort(z.begin(), z.end()) // Sort vector z in ascending order
#define rsort(z) sort(z.rbegin(), z.rend()) // Sort vector z in descending order
#define eerase(z) z.erase(unique(z.begin(), z.end()), z.end()) // Remove duplicate elements from vector z
#define rep(i,a,n) for(Int (i)=(a); (i)<(n); (i)++) // Iterate through a range of integers
#define repq(i,a,n) for(Int (i)=(a); (i)<=(n); (i)++) // Iterate through a range of integers up to n
const int MAX_N = 1000000; // Define constant for maximum number
const Int MAX_N_Int = 1000000000000; // Define constant for maximum long integer

// Template function to print the contents of a vector
template <typename T>
void printV(const std::vector<T>& v, const char * const separator = " ") {
    if(!v.empty()) { // Check if vector is empty before printing
        std::copy(v.begin(),
                  --v.end(),
                  std::ostream_iterator<T>(std::cout, separator)); // Print vector elements separated by separator
        std::cout << v.back() << "\n"; // Print last element
    }
}

// Function to check if a number is prime
bool isPrime(int num) {
    if (num < 2) return false; // 2 is the smallest prime number
    else if (num == 2) return true; // 2 is a prime number
    else if (num % 2 == 0) return false; // Even numbers greater than 2 are not prime

    double sqrtNum = sqrt(num); // Calculate square root of number
    for (int i = 3; i <= sqrtNum; i += 2) { // Iterate through odd numbers up to square root
        if (num % i == 0) { // If number is divisible by current odd number
            return false; // It's not a prime number
        }
    }

    // If number is not divisible by any odd number up to its square root, it's a prime number
    return true;
}

Int gcd(Int a, Int b) {
    return b != 0 ? gcd(b, a % b) : a; // Recursive function to find greatest common divisor
}

Int lcm(Int a, Int b) {
    return a / gcd(a, b) * b; // Find least common multiple by multiplying greatest common divisor and smaller number
}

int Max(int a, int b, int c) {
    int temp = max(a, b); // Find maximum of two numbers
    return max(temp, c); // Compare maximum with third number and return the result
}

int Min(int a, int b, int c) {
    int temp = min(a, b); // Find minimum of two numbers
    return min(temp, c); // Compare minimum with third number and return the result
}

bool integer(double num) {
    return floor(num) == num; // Check if a number is an integer
}

Int fact(int num) {
    if (num == 0) // Base case: factorial of 0 is 1
        return 1;
    else
        return num * fact(num - 1); // Recursive call to calculate factorial
}

Int yakusu(int n) {
    int cnt = 0; // Initialize divisor count
    for (int i = 1; i * i <= n; i++) { // Iterate through divisors up to square root of n
        if (n % i == 0) { // If n is divisible by current divisor
            cnt++; // Increment divisor count
            if (i * i != n) cnt++; // If n has more than one divisor, increment count
        }
    }
    return cnt; // Return divisor count
}

Int fact_mod(Int n, Int mod) {
    Int f = 1; // Initialize factorial to 1
    repq(i,2,n) f = f * (i % MOD) % MOD; // Calculate factorial modulo m
    return f; // Return the result
}

// Function to calculate x^n modulo m using repeated squaring method
Int mod_pow(Int x, Int n, Int mod) {
    Int res = 1; // Initialize result to 1
    while(n > 0) { // While n is not zero
        if(n & 1) res = (res * x) % mod; // If n is odd, multiply x with result and reduce modulo m
        x = (x * x) % mod; // Square x and reduce modulo m
        n >>= 1; // Divide n by 2
    }
    return res; // Return the final result
}

// Function to calculate the number of combinations of n items taken r at a time modulo m
Int combination_mod(Int n, Int r, Int mod) {
    if(r > n-r) r = n-r; // Adjust r if it's greater than the difference between n and r
    if(r == 0) return 1; // Base case: combination of 0 items is 1
    Int a = 1; // Initialize first term
    rep(i, 0, r) a = a * ((n-i) % MOD) % MOD; // Calculate first term
    Int b = mod_pow(fact_mod(r, mod), mod-2, mod); // Calculate second term
    return (a % MOD) * (b % MOD) % MOD; // Multiply terms and reduce modulo m
}

bool rev(string s){
    string t=s; // Create a copy of string s
    reverse(s.begin(),s.end()); // Reverse string s in place
    return s==t; // Check if original string is equal to its reversed version
}

int main() {
    // Initialize I/O streams
    IOS;
    // Set precision for floating point numbers
    prec;

    Int k, a, b; // Initialize variables a, b, and k
    cin >> k >> a >> b; // Read input values for k, a, and b

    # <START-OF-CODE>
    # 