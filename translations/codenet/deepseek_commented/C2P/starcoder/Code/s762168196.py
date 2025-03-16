# Step 1: Include necessary headers
import sys

# Step 2: Define the main function
def main():

    # Step 3: Declare necessary variables
    a = []
    min = 0
    max = 0
    n = 0
    sum = 0

    # Step 4: Read the number of elements (n) from the user
    n = int(raw_input())

    # Step 5: Read the elements of the array from the user and calculate the sum
    for i in range(0, n):
        a.append(int(raw_input()))
        sum += a[i]

    # Step 6: Find the minimum and maximum values in the array
    max = min = a[0]
    for i in range(1, n):
        if a[i] > max: max = a[i]
        if a[i] < min: min = a[i]

    # Step 7: Print the minimum, maximum, and sum of the elements
    print min, max, sum

# Step 8: Call the main function
if __name__ == "__main__":
    main()

# 