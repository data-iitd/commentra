int main() {
    int i, j, k, n; // Declare integer variables i, j, k, and n
    
    // Read an integer input from the user
    std::cin >> n;
    
    // Calculate and print the result based on the input n
    // The expression (24 + (24 - n)) simplifies to (48 - n)
    std::cout << (24 + (24 - n)) << std::endl;
    
    return 0; // Return 0 to indicate successful execution
}
