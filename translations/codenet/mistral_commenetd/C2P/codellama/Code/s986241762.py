
#include <stdio.h>
# Declare the main function
int main():
    int n; # Declare and initialize an integer variable 'n'
    long sum=0; # Declare and initialize a long integer variable 'sum' with zero value

    # Read the number of elements in the array from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);

    # Declare an integer array 'a' of size 'n'
    int a[n];

    # Read the elements of the array from the user
    printf("Enter %d integers:\n", n);
    for i in range(n):
        printf("Enter element number %d: ", i+1);
        scanf("%d",&a[i]); # Read an integer value and store it in the array 'a'

    # Calculate the sum of the differences between adjacent elements in the array
    for i in range(1,n):
        # Check if the previous element is greater than the current element
        if a[i-1]>a[i]:
            # If true, add the difference to the sum
            sum += a[i-1]-a[i];
            # Swap the elements to maintain the array in non-decreasing order
            a[i] = a[i-1];

    # Print the sum of the differences
    printf("The sum of the differences is: %ld\n", sum);

