import sys  # Import the sys module for reading input

def find(li, from_index, target):  # Define the find function
    low = from_index  # Initialize the lower bound of the binary search
    upp = len(li) - 1  # Initialize the upper bound of the binary search

    if upp < low:  # Check if the list is empty
        return 0
    elif li[from_index] >= target:  # Check if the target is greater than or equal to the first element
        return 0
    elif li[upp] < target:  # Check if the target is less than the last element
        return upp - low + 1

    while upp - low > 1:  # Perform the binary search
        mid = (low + upp) // 2  # Calculate the middle index

        if li[mid] >= target:  # If the middle element is greater than or equal to the target
            upp = mid  # Update the upper bound
        else:  # If the middle element is less than the target
            low = mid  # Update the lower bound

    return low - from_index + 1  # Return the count of elements greater than the target

def main():  # Define the main function
    N = int(sys.stdin.readline().strip())  # Read the first integer N from input
    L = list(map(int, sys.stdin.readline().strip().split()))  # Read N integers into a list

    L.sort()  # Sort the list

    count = 0  # Initialize a counter variable to 0

    for i in range(N):  # Iterate through all pairs of elements in the sorted list
        for j in range(i + 1, N):
            a = L[i]  # Get the first integer of the pair
            b = L[j]  # Get the second integer of the pair
            res = find(L, j + 1, a + b)  # Call the find function
            count += res  # Add the result to the counter

    print(count)  # Print the final count

if __name__ == "__main__":  # Check if the script is being run directly
    main()  # Call the main function

# <END-OF-CODE>
