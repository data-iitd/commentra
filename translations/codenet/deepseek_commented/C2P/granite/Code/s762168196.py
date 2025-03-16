
# Step 1: Import necessary libraries
import sys

# Step 2: Define the main function
def main():

    # Step 3: Read the number of elements (n) from the user
    n = int(input())

    # Step 4: Read the elements of the array from the user and calculate the sum
    a = list(map(int, input().split()))
    sum = sum(a)

    # Step 5: Find the minimum and maximum values in the array
    max = min = a[0]
    for i in range(1, n):
        if a[i] > max: max = a[i]
        if a[i] < min: min = a[i]

    # Step 6: Print the minimum, maximum, and sum of the elements
    print(min, max, sum)

# Step 7: Call the main function
if __name__ == "__main__":
    main()

