#include <iostream>
#include <iomanip>
#include <math.h>
#include <list>
#include <algorithm>
#include <set>
#include <vector>
#include <math.h>
#include <map>
#include <string>
#include <numeric>
#include <queue>
#include <sstream>
#include <bitset>
#include <stack>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using sll = set<long long>;

# Function to compute the greatest common divisor (GCD) of two numbers
def gcd(a, b):
    return b if b == 0 else gcd(b, a % b)

# Function to compute the least common multiple (LCM) of two numbers
def lcm(a, b):
    return a * b // gcd(a, b)

# Function to get the prime factorization of a number
def getPrimeFactor(n):
    res = {}
    # Iterate from 2 to the square root of n
    for i in range(2, int(sqrt(n)) + 1):
        # While i divides n, store i in the result map
        while n % i == 0:
            res[i] = res.get(i, 0) + 1
            n //= i
    # If n is still greater than 1, it is a prime factor
    if n != 1:
        res[n] = 1
    return res

# Function to check if a number is prime
def IsPrimeNumber(num):
    if num <= 2:
        return True # 0, 1, and 2 are considered prime
    elif num % 2 == 0:
        return False # Exclude even numbers

    sqrtNum = sqrt(num)
    # Check for factors from 3 to the square root of num
    for i in range(3, int(sqrtNum) + 1, 2):
        if num % i == 0:
            return False # Found a factor, not prime
    return True # No factors found, num is prime

# Function to compute modular inverse using the Extended Euclidean Algorithm
def modinv(a, m):
    b, u, v = m, 1, 0
    # Loop until b becomes zero
    while b:
        t = a // b
        a, b = b, a % b
        u, v = v, u - t * v
    u %= m # Ensure u is within the modulo
    if u < 0:
        u += m # Adjust if u is negative
    return u # Return the modular inverse

# Macro definitions for loop iterations
def rep(i, s, e):
    for i in range(s, e):
        yield i

def repeq(i, s, e):
    for i in range(s, e + 1):
        yield i

def main():
    N, K = map(int, input().split())

    A = [0] * (N + 1)
    # Input the elements into the vector A
    for i in range(1, N + 1):
        A[i] = int(input())

    cur = 1 # Initialize current position
    dic = [-1] * (N + 1) # Dictionary to store the first occurrence of each index
    flg = False # Flag to indicate if we have entered a cycle

    # Process the sequence based on the value of K
    for i in range(1, K + 1):
        # If current index has not been seen before or we are in a cycle
        if dic[cur] < 0 or flg:
            dic[cur] = i # Record the current index
            cur = A[cur] # Move to the next index
        # If we have seen this index before and are not in a cycle
        else:
            tmp = K - (dic[cur] - 1) # Calculate remaining steps
            tmp %= i - dic[cur] # Adjust steps based on the cycle length
            i = K - tmp # Update i to skip to the end of the cycle
            flg = True # Set the flag indicating we are in a cycle

    # Output the final position after K steps
    print(cur)

if __name__ == "__main__":
    main()

