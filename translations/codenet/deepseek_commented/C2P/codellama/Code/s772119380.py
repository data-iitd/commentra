#include <stdio.h>

int main()
{
    # Declare variables
    int a[1000], n, i, j, d = 0

    # Read the number of elements in the array
    scanf("%d", &n)

    # Read the elements of the array
    for i in range(0, n):
        scanf("%d", &a[i])

    # Bubble sort algorithm to sort the array in ascending order
    for i in range(0, n):
        for j in range(n - 1, i + 1, -1):
            if a[j] < a[j - 1]:
                # Swap the elements if they are in the wrong order
                temp = a[j]
                a[j] = a[j - 1]
                a[j - 1] = temp
                # Increment the swap counter
                d += 1

    # Print the sorted array
    print(a[0])
    for i in range(1, n):
        print(" %d", a[i])
    print("\n")

    # Print the number of swaps made during the sorting process
    print(d)

    return 0
}

