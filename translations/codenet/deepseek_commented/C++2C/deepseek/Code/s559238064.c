#include <cmath>          // Include cmath for mathematical functions
#include <cstring>        // Include cstring for string manipulation functions
#include <iostream>       // Include iostream for input and output operations
#include <algorithm>      // Include algorithm for general algorithms like sort

typedef long long ll;    // Define ll as an alias for long long
const int inf = 0x3f3f3f3f; // Define inf as a large value (0x3f3f3f3f)
const int mod = (1 ? 1e9 + 7 : 998244353); // Define mod as either 1e9 + 7 or 998244353

int main()
{
    // Optimize input/output operations
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ll a, b, c, d, e, f, g, T; // Declare variables to store input values
    char z[1000]; // Declare a character array to store input string
    std::cin >> z; // Read input string from standard input
    int a = strlen(z); // Calculate the size of the string and store it in a
    for (int i = 0; i < a - 1; i++) // Iterate through the string
    {
        if (z[i] == z[i + 1]) // Check if any two consecutive characters are the same
        {
            std::cout << "Bad" << std::endl; // Print "Bad" if a pair is found and exit
            return 0;
        }
    }
    std::cout << "Good" << std::endl; // Print "Good" if no pair is found
}
