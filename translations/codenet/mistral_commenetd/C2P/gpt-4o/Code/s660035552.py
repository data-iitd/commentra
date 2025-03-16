# Import necessary libraries
import sys

# Initialize low and high arrays for quicksort
low = [0] * 200000
high = [0] * 200000

# Function to partition the array using quicksort algorithm
def part(a, b, l, r):
    i = l - 1  # Initialize index 'i' for smaller elements
    j = r      # Initialize index 'j' for greater elements
    x = b[r]   # Set pivot as last element

    while True:  # While loop for partitioning
        while i + 1 < r and b[i + 1] < x:
            i += 1  # Move 'i' to next smaller element
        while j > l and x < b[j - 1]:
            j -= 1  # Move 'j' to previous greater element

        if i >= j:
            break  # If 'i' and 'j' meet, partitioning is done

        # Swap elements in 'a' and 'b' arrays
        a[i], a[j] = a[j], a[i]
        b[i], b[j] = b[j], b[i]

    # Swap pivot with last element in 'a' and 'b' arrays
    a[i], a[r] = a[r], a[i]
    b[i], b[r] = b[r], b[i]
    return i  # Return index of pivot

# Function to perform quicksort on the array 'a'
def quicksort(a, b, n):
    sp = 0  # Stack pointer
    low[sp] = 0  # Initialize 'low' stack with base index 0
    high[sp] = n - 1  # Initialize 'high' stack with top index 'n-1'
    sp += 1  # Increment stack pointer

    while sp > 0:  # While stack is not empty
        sp -= 1  # Decrement stack pointer
        l = low[sp]  # Get base index 'l' from stack
        r = high[sp]  # Get top index 'r' from stack

        if l >= r:  # If base and top indices are same, no need to partition
            continue  # Skip this iteration

        v = part(a, b, l, r)  # Partition the array

        if v - l < r - v:  # If partitioning moved pivot to left
            low[sp] = v + 1
            high[sp] = r
            sp += 1
            low[sp] = l
            high[sp] = v - 1
        else:  # If partitioning moved pivot to right
            low[sp] = l
            high[sp] = v - 1
            sp += 1
            low[sp] = v + 1
            high[sp] = r

# Main function to read input and call quicksort
def main():
    n, m = map(int, sys.stdin.readline().split())  # Read number of elements 'n' and queries 'm'
    a = [0] * m  # Initialize array 'a' of size m
    b = [0] * m  # Initialize array 'b' of size m

    for i in range(m):
        a[i], b[i] = map(int, sys.stdin.readline().split())  # Read elements and their corresponding queries

    quicksort(a, b, m)  # Call quicksort function to sort elements

    t = 0  # Initialize counter to 0
    cnt = 0  # Initialize counter for unique elements
    for i in range(m):  # Iterate through sorted elements
        if t <= a[i]:  # If current element is greater than previous element
            t = b[i]  # Set current query as new temporary storage
            cnt += 1  # Increment counter

    print(cnt)  # Print the number of unique queries

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
