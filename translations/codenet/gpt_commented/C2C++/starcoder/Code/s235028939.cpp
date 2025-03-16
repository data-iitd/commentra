#include <iostream>

int main()
{
    // Declare two integer variables n and m
    int n, m;

    // Read two integers from standard input
    // n represents the number of rows, and m represents the number of columns
    std::cin >> n >> m;

    // Calculate the product of (n - 1) and (m - 1)
    // This represents the number of internal edges in a grid of n by m cells
    std::cout << (n - 1) * (m - 1) << std::endl;

    // Return 0 to indicate successful completion of the program
    return 0;
}
