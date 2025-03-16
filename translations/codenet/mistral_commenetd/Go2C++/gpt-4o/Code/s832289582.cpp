// Include necessary headers
#include <iostream> // For input and output
#include <string>   // For string manipulation
#include <vector>   // For using vectors
#include <sstream>  // For string stream
#include <cstdlib>  // For atoi

// Function to check if any subnumber of given string S is divisible by prime number P
int checkSubNumbers(int N, int P, const std::string& S);

// Function to check if any subnumber of given string S is divisible by prime number P equal to 2 or 5
int checkTwoOrFive(int N, int P, const std::string& S);

// Function to check if any subnumber of given string S is divisible by prime number P which is not equal to 2 or 5
int checkNotTwoNorFive(int N, int P, const std::string& S);

int main() {
    int N, P;
    std::string S;

    // Read N, P, and S from standard input
    std::cin >> N >> P >> S;

    // Call checkSubNumbers function and store the result in answer variable
    int answer = checkSubNumbers(N, P, S);

    // Print the answer
    std::cout << answer << std::endl;

    return 0;
}

int checkSubNumbers(int N, int P, const std::string& S) {
    // Switch statement to check if P is equal to 2 or 5
    switch (P) {
        case 2:
        case 5:
            return checkTwoOrFive(N, P, S); // If P is equal to 2 or 5, call checkTwoOrFive function
        default:
            return checkNotTwoNorFive(N, P, S); // If P is not equal to 2 or 5, call checkNotTwoNorFive function
    }
}

int checkTwoOrFive(int N, int P, const std::string& S) {
    int answer = 0; // Initialize answer variable as 0
    int n; // Define an integer variable n

    // Iterate through the string S from the last character to the first character
    for (int i = N - 1; i >= 0; i--) {
        // Convert the substring from i to i+1 to an integer n
        n = S[i] - '0';
        // If n is divisible by P, add its index to the answer variable
        if (n % P == 0) {
            answer += i + 1;
        }
    }
    return answer;
}

int checkNotTwoNorFive(int N, int P, const std::string& S) {
    int multiplier = 1; // Initialize multiplier variable as 1
    int answer = 0;     // Initialize answer variable as 0
    std::vector<int> remainderLookup(P, 0); // Create a vector for storing the count of remainders
    int prevRemainder = -1; // Initialize prevRemainder variable as -1

    // Iterate through the string S from the last character to the first character
    for (int i = N - 1; i >= 0; i--) {
        // Get the digit from the string S at the current index i
        int digit = S[i] - '0';
        int remainder;

        // If prevRemainder is equal to -1, get the remainder of the first digit by dividing it by P
        if (prevRemainder == -1) {
            remainder = digit % P;
        } else {
            // Otherwise, calculate the new remainder
            remainder = (((multiplier * digit) % P) + prevRemainder) % P;
        }

        // If the remainder is equal to 0, add 1 to the answer variable
        if (remainder == 0) {
            answer++;
        }

        // Get the count of the current remainder from the vector remainderLookup
        int count = remainderLookup[remainder];
        // Add the count to the answer variable
        answer += count;
        // Update the vector remainderLookup with the new count of the current remainder
        count++;
        remainderLookup[remainder] = count;

        // Update the multiplier variable as multiplier * 10 % P
        prevRemainder = remainder;
        multiplier = (multiplier * 10) % P;
    }
    return answer;
}

// <END-OF-CODE>
