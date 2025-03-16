#include <stdio.h>  # Step 1: Include necessary headers

def main():  # Step 1: Define the main function

    # Step 2: Declare necessary variables
    a = [0] * 10000
    min = max = n = i = 0
    sum = 0

    # Step 3: Read the number of elements (n) from the user
    n = int(input())

    # Step 4: Read the elements of the array from the user and calculate the sum
    for i in range(n):
        a[i] = int(input())
        sum += a[i]

    # Step 5: Find the minimum and maximum values in the array
    max = min = a[0]
    for i in range(1, n):
        if a[i] > max:
            max = a[i]
        if a[i] < min:
            min = a[i]

    # Step 6: Print the minimum, maximum, and sum of the elements
    print(min, max, sum)

if __name__ == "__main__":
    main()  # Step 7: Call the main function

