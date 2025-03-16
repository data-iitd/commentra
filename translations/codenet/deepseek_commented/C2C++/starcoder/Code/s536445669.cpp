#include <iostream>  // Include the standard input-output header file

int main(void)
{
        int n, k;
        std::cin >> n >> k;  // Read two integers from the standard input
        if (n % k == 0)         // Check if n is divisible by k
            std::cout << "0\n";      // If true, print 0
        else
            std::cout << "1\n";      // If false, print 1
        return 0;               // Return 0 to indicate successful execution
}

