
#include <iostream>
#include <cmath>

int main() {
    // Create a Scanner object to read input from the console
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    
    // Read three long integers from input: N, A, and B
    long long N, A, B;
    std::cin >> N >> A >> B;
    
    // Initialize a variable k to count how many complete cycles of (A + B) can fit into N
    long long k = 0;

    // Check if the input values are within the specified constraints
    if (1 <= N && N <= std::pow(10, 18) && 0 <= A && 0 <= B && 0 < A + B && A + B <= std::pow(10, 18)) {
        
        // Case 1: If the sum of A and B is less than or equal to N
        if (A + B <= N) {
            // Calculate how many complete cycles of (A + B) fit into N
            k = N / (A + B);
            
            // Check if the remaining part after k cycles is greater than A
            if (N - k * (A + B) > A) {
                // Print the total amount produced using k cycles and the remaining part
                std::cout << A * k + (N - k * (A + B)) - (N - (k * (A + B) + A)) << std::endl;
            } else {
                // Print the total amount produced using k cycles and the remaining part
                std::cout << A * k + (N - k * (A + B)) << std::endl;
            }
        } 
        // Case 2: If the sum of A and B is greater than N but A is less than or equal to N
        else if (A + B > N && A <= N) {
            // If A is less than or equal to N, print A
            std::cout << A << std::endl;
        } 
        // Case 3: If A + B is greater than N and A is greater than N
        else {
            // Print the total amount N, as no complete cycles can be formed
            std::cout << N << std::endl;
        }
    }
    
    return 0;
}
