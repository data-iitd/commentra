
#include <stdio.h> // Include the necessary header file for input/output

int main() {
    int n; // Declare and initialize the size of the array n
    scanf("%d", &n); // Read the size of the array from the user

    int arr[n]; // Declare an array of size n
    int sum = 0; // Initialize sum to 0

    // Read n integers from the user and store them in the array arr, while updating the sum
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int c = 0; // Initialize count of valid elements to remove
    char sb[1000]; // Create a character array to store the output string
    sb[0] = '\0'; // Initialize the output string as an empty string

    // Iterate through the array arr to find elements that can be removed
    for (int i = 0; i < n; i++) {
        // Check if removing the current element keeps the average unchanged
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) {
            c++; // Increment the count
            sprintf(sb, "%s%d ", sb, i + 1); // Append the index (plus one) to the output string
        }
    }

    // Print the count of valid elements and the indices of these elements
    printf("%d\n", c);
    printf("%s\n", sb);

    return 0; // Return 0 to indicate successful execution
}
