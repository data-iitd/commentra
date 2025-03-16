#include<stdio.h>

int main() {
    # Declare variables
    n = 0
    i = 0
    j = 0
    m = 0
    s = 0
    t = 0

    # Read the number of elements in the array
    scanf("%d", &n)
    
    # Declare an array of size n
    a = [0] * n

    # Read n elements into the array
    for i in range(n):
        scanf("%d", &a[i])

    # Initialize total sum variable
    t = 0

    # Outer loop to iterate through each element of the array
    for i in range(n):
        # Initialize sum for the current element
        s = 0

        # Inner loop to calculate the product of the current element with all subsequent elements
        for j in range(1, n):
            # Skip elements that are not after the current element
            if j <= i:
                continue

            # Calculate the product of the current element a[i] and a[j]
            m = a[i] * a[j]

            # Add the product to the sum for the current element
            s = s + m

        # Add the sum of products for the current element to the total
        t = t + s

    # Print the total sum of products
    printf("%d\n", t)

    # Return success status
    return 0
}

