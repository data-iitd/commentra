#include <iostream>
#include <vector>

int main() {
    int N; // Declare an integer variable to store the number of elements
    std::cin >> N; // Read the value of N from the standard input

    std::vector<int> A(N); // Declare a vector A of size N to store the elements
    long long sum = 0; // Initialize sum to store the sum of elements
    long long wa = 0; // Initialize wa to store the weighted sum
    long long min = 1123456789; // Initialize min to store the minimum value

    // Use a for loop to read the elements of the array A and calculate the sum and wa
    for (int i = 0; i < N; i++) {
        std::cin >> A[i]; // Read the elements of the array A
        sum += A[i]; // Add the current element to sum
        wa += i + 1; // Add the current index+1 to wa
    }

    // Check if the sum is divisible by wa
    if (sum % wa != 0) {
        std::cout << "NO" << std::endl; // If not, print "NO"
        return 0; // Return 0 to indicate successful execution
    }

    int shou = sum / wa; // Calculate the quotient shou
    std::vector<int> sa(N); // Declare a vector sa of size N to store the differences between consecutive elements

    // Calculate the differences between consecutive elements and store them in the vector sa
    for (int i = 0; i < N; i++) {
        sa[i] = A[(i + 1) % N] - A[i] - shou;
    }

    // Check if all differences are less than or equal to 0 and divisible by N
    for (int i = 0; i < N - 1; i++) {
        if (sa[i] <= 0 && sa[i] % N == 0) {
            continue; // If so, continue to the next iteration
        } else {
            std::cout << "NO" << std::endl; // Otherwise, print "NO"
            return 0; // Return 0 to indicate successful execution
        }
    }

    std::cout << "YES" << std::endl; // Print "YES"
    return 0; // Return 0 to indicate successful execution
}
