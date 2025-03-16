#define _GLIBCXX_DEBUG // Enables debugging features for the C++ standard library
#include <iostream> // For input and output operations
#include <cstdio> // For standard input and output operations
#include <vector> // To use the vector container
#include <algorithm> // For various algorithms including std::sort
#include <utility> // For std::pair
#include <string> // To use the string class
#include <map> // To use the map container
using namespace std; // To avoid prefixing standard library names with 'std::'
typedef long long ll; // Defines 'll' as an alias for 'long long'
#define ALL(v) (v).begin(), (v).end() // Defines a macro to get the begin and end of a container
const int inf = 1e9; // Defines a constant for infinity
const int mod = 1e9+7; // Defines a constant for modulo operation

// Function to check if a number is prime
boolean is_prime(ll x) {
    for (ll i = 2; i*i <= x; i++) // Iterates from 2 to the square root of x
        if (x % i == 0) return false; // Returns false if x is divisible by i
    return true; // Returns true if no divisors are found
}

public class Main {
    public static void main(String[] args) {
        int N;
        Scanner sc = new Scanner(System.in); // Creates a Scanner object to read input from standard input
        N = sc.nextInt(); // Reads an integer N from standard input

        ll ans = 1; // Initializes the answer variable to 1
        for (int i = 2; i <= N; i++) { // Iterates from 2 to N
            if (is_prime((ll)i)) { // Checks if the current number i is prime
                int NN = N;
                int cnt = 0; // Initializes a counter to count the power of the prime
                while (NN) { // While loop to calculate the power of the prime in N
                    cnt += NN/i; // Adds the quotient of NN divided by i to cnt
                    NN /= i; // Divides NN by i
                }
                ans *= cnt+1; // Multiplies ans by cnt+1
                ans %= mod; // Takes modulo mod to prevent overflow
            }
        }

        System.out.println(ans); // Prints the final answer
    }
}

