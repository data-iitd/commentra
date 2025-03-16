#include <iostream>
#include <vector>

int main() {
    int N; // Declare an integer variable to store the number of elements
    std::cin >> N; // Read the value of N from the standard input

    long long sum = 0; // Initialize sum to store the sum of elements
    long long wa = 0; // Initialize wa to store the weighted sum
    std::vector<int> A(N); // Declare a vector A of size N to store the elements
    std::vector<int> sa(N); // Declare a vector sa of size N to store the differences between consecutive elements
    int ans = 0; // Initialize ans to store the result
    int shou; // Declare an integer variable shou to store the quotient
    long long min = 1123456789; // Initialize min to store the minimum value

    // Use a for loop to read the elements of the vector A and calculate the sum and wa
    for (int i = 0; i < N; i++) {
        std::cin >> A[i]; // Read the elements of the vector A
        sum += A[i]; // Add the current element to sum
        wa += i + 1; // Add the current index + 1 to wa
    }

    // Check if the sum is divisible by wa
    if (sum % wa) ans = 0; // If not, set ans to 0
    else {
        shou = sum / wa; // Calculate the quotient shou
        // Calculate the differences between consecutive elements and store them in the vector sa
        for (int i = 0; i < N; i++) {
            sa[i] = A[(i + 1) % N] - A[i] - shou;
        }

        // Check if all differences are less than or equal to 0 and divisible by N
        for (int i = 0; i < N - 1; i++) {
            if (sa[i] <= 0 && !(sa[i] % N))
                ans = 1; // If so, set ans to 1
            else {
                ans = 0; // Otherwise, set ans to 0 and break the loop
                break;
            }
        }
    }

    // Print "YES" if ans is 1, otherwise print "NO"
    if (ans) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;

    return 0; // Return 0 to indicate successful execution
} // <END-OF-CODE>
