
#include <iostream>  // Step 1: Include necessary headers

int main() {  // Step 1: Define the main function

    // Step 2: Declare necessary variables
    int a[10000], min, max, n, i;
    long long sum = 0;

    // Step 3: Read the number of elements (n) from the user
    std::cin >> n;

    // Step 4: Read the elements of the array from the user and calculate the sum
    for(i = 0; i < n; i++){
        std::cin >> a[i];
        sum += a[i];
    }

    // Step 5: Find the minimum and maximum values in the array
    max = min = a[0];
    for(i = 1; i < n; i++){
        if(a[i] > max) max = a[i];
        if(a[i] < min) min = a[i];
    }

    // Step 6: Print the minimum, maximum, and sum of the elements
    std::cout << min << " " << max << " " << sum << std::endl;

    return 0;  // End of the main function
}
