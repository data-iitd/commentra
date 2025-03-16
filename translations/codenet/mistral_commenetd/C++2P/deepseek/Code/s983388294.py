import sys

# Function to read an integer from the standard input
def main():
    # Initialize variables
    n = int(input("Enter the number of elements in the array: "))

    # Allocate memory for the array and read its elements
    a = []
    for i in range(n):
        a.append(int(input(f"Enter element {i+1}: ")))

    # Initialize a counter to keep track of the current element in the array
    curr = 0

    # Iterate through the array and increment the counter whenever the current element is one more than the previous one
    for i in range(n):
        if a[i] == curr + 1:
            curr += 1

    # Check if the counter is greater than zero, and if so, print the number of elements that are not consecutive
    if curr > 0:
        print(f"The array has {n - curr} non-consecutive elements.")

    # If the counter is zero, print -1 to indicate that all elements are not consecutive
    else:
        print("-1")

# Call the main function
if __name__ == "__main__":
    main()
