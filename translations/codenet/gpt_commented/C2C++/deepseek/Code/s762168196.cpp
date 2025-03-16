#include <iostream>
#include <vector>

int main()
{
    // Declare a vector to hold up to 10,000 integers
    std::vector<int> a(10000);
    int n, i;
    // Initialize variables to hold the sum of the integers, minimum, and maximum
    long long sum = 0;
    int min, max;

    // Read the number of integers to be processed
    std::cin >> n;

    // Read n integers from input and calculate their sum
    for(i = 0; i < n; i++){
        std::cin >> a[i]; // Read each integer into the vector
        sum += a[i];      // Add the integer to the sum
    }

    // Initialize min and max with the first element of the vector
    min = max = a[0];

    // Iterate through the vector to find the minimum and maximum values
    for(i = 1; i < n; i++){
        if(a[i] > max) max = a[i]; // Update max if the current element is greater
        if(a[i] < min) min = a[i]; // Update min if the current element is smaller
    }

    // Print the minimum, maximum, and sum of the integers
    std::cout << min << " " << max << " " << sum << std::endl;

    return 0; // Indicate that the program ended successfully
}
