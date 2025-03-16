#include<iostream>
using namespace std;

int main() {
    // Declare variables
    int N, ans, i, count;

    // Read the number of elements in the array
    cin >> N;

    # Declare an array of size N
    A = [0] * N

    # Input the elements into the array
    for i in range(N):
        cin >> A[i]

    # Initialize index and counters
    i = 0
    ans = 0    # To store the final answer
    count = 0  # To count consecutive equal elements

    # Loop through the array until the second last element
    while A[i + 1] != NULL:
        # Check if the current element is equal to the next element
        if A[i] == A[i + 1]:
            count += 1 # Increment count for consecutive elements
            
            # If count is odd, increment the answer
            if count % 2 != 0:
                ans += 1
        else:
            # Reset count if elements are not equal
            count = 0
        i += 1 # Move to the next element

    # Output the final answer
    print(ans)
    return 0 # End of the program
}

