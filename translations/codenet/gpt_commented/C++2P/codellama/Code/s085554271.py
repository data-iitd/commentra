#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
#include <iterator>
#include <map>
#include <fstream>
#include <iomanip>

using namespace std;

#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define prec std::cout << std::fixed << std::setprecision(15);
#define endl "\n"
#define MOD 1000000007
#define Int int64_t
#define PI 3.14159265358979
#define ssort(z) sort(z.begin(), z.end())
#define rsort(z) sort(z.rbegin(), z.rend())
#define eerase(z) z.erase(unique(z.begin(), z.end()), z.end())
#define ccnt(z, w) count(z.begin(), z.end(), w)
#define rep(i,a,n) for(Int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(Int (i)=(a); (i)<=(n); (i)++)

# Function to print a vector with a specified separator
def printV(v, separator = " "):
    if not v.empty():
        copy(v.begin(),
             --v.end(),
             ostream_iterator<T>(cout, separator))
        cout << v.back() << "\n"

# Function to check if a number is prime
def isPrime(num):
    if num < 2:
        return False # Numbers less than 2 are not prime
    elif num == 2:
        return True # 2 is prime
    elif num % 2 == 0:
        return False # Exclude even numbers

    sqrtNum = sqrt(num) # Calculate square root for optimization
    for i in range(3, sqrtNum + 1, 2): # Check for factors from 3 to sqrt(num)
        if num % i == 0:
            return False # Not a prime number

    return True # Number is prime

# Function to calculate the greatest common divisor (GCD)
def gcd(a, b):
    return b if b == 0 else gcd(b, a % b) # Recursive GCD calculation

# Function to calculate the least common multiple (LCM)
def lcm(a, b):
    return a / gcd(a, b) * b # LCM using GCD
    # a*b may cause 64-bit integer overflow

# Function to find the maximum of three integers
def Max(a, b, c):
    temp = max(a, b)
    return max(temp, c) # Return the maximum value

# Function to find the minimum of three integers
def Min(a, b, c):
    temp = min(a, b)
    return min(temp, c) # Return the minimum value

# Function to check if a double is an integer
def integer(num):
    return floor(num) == num # Check if the number is an integer

# Recursive function to calculate factorial
def fact(num):
    if num == 0:
        return 1 # Base case for factorial
    else:
        return num * fact(num - 1) # Recursive case

# Function to count the number of divisors of n
def yakusu(n):
    cnt = 0 # Counter for divisors
    for i in range(1, n + 1):
        if n % i == 0:
            cnt += 1 # Count the divisor
            if i * i != n:
                cnt += 1 # Count the complementary divisor if it's different

    return cnt # Return the count of divisors

# Function to calculate factorial modulo a given number
def fact_mod(n, mod):
    f = 1
    for i in range(2, n + 1):
        f = f * (i % mod) % mod # Calculate factorial with modulo

    return f # Return the result

# Function to perform modular exponentiation
def mod_pow(x, n, mod):
    res = 1
    while n > 0:
        if n & 1:
            res = (res * x) % mod # If n is odd, multiply x with result
        x = (x * x) % mod # Square x
        n >>= 1 # Divide n by 2

    return res # Return the result

# Function to calculate combinations nCr modulo a given number
def combination_mod(n, r, mod):
    if r > n - r:
        r = n - r # Use symmetry property of combinations
    if r == 0:
        return 1 # Base case for combinations
    a = 1
    for i in range(0, r):
        a = a * ((n - i) % mod) % mod # Calculate numerator
    b = mod_pow(fact_mod(r, mod), mod - 2, mod) # Calculate denominator using Fermat's Little Theorem

    return (a % mod) * (b % mod) % mod # Return the result

# Function to check if a string is a palindrome
def rev(s):
    t = s
    reverse(s.begin(), s.end()) # Reverse the string
    return s == t # Check if the original string is equal to the reversed string

# Main function
def main():
    IOS # Optimize input/output
    prec # Set precision for output
    a, b, c, n, m, k, x, y = 0, 0, 0, 0, 0, 0, 0, 0 # Declare variables
    str, s, t, u = "", "", "", "" # Declare string variables
    cin >> k >> a >> b # Input values for k, a, and b

    # Check for multiples of k in the range [a, b]
    for i in range(a, b + 1):
        if i % k == 0:
            print("OK") # Output OK if a multiple is found
            return 0 # Exit the program

    print("NG") # Output NG if no multiples are found

    print() # Print a newline
    return 0 # Return success

