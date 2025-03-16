
#include<iostream> // Include the standard input/output library

int main() // The entry point of the program
{
    int n; // Declare an integer variable 'n' to store the number of elements in the array
    int i, j, m, s, t; // Declare integer variables 'i', 'j','m','s', and 't' for iteration and summation

    std::cin >> n; // Read an integer value from the standard input and store it in 'n'

    int a[n]; // Declare an integer array 'a' of size 'n'

    for(i=0;i<n;i++){ // Iterate through each element of the array 'a'
        std::cin >> a[i]; // Read an integer value from the standard input and store it in the current element of array 'a'
    }

    t=0; // Initialize the variable 't' to zero

    for(i=0;i<n;i++){ // Iterate through each element of the array 'a'
        s=0; // Initialize the variable's' to zero for summation

        for(j=1;j<n;j++){ // Iterate through all other elements of the array 'a' except the current element 'i'
            if(j <= i){ // If the current index 'j' is less than or equal to the current index 'i', then skip the iteration
                continue;
            }

            m = a[i] * a[j]; // Multiply the current element 'a[i]' with the next element 'a[j]' and store the result in'm'

            s = s + m; // Add the product'm' to the sum's'
        }

        t = t + s; // Add the sum's' to the total sum 't'
    }

    std::cout << t << std::endl; // Print the total sum 't' to the standard output

    return 0; // Indicate successful termination of the program
}

