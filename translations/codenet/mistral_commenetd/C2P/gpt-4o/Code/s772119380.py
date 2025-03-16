# This is the main function where the program starts execution
def main():
    # Declare an integer list 'a' and an integer variable 'n'
    a = []
    n = int(input())  # Read the size of the array from the user

    # Read 'n' integers from the user and store them in the list 'a'
    for i in range(n):
        a.append(int(input()))  # Read an integer and store it in the list 'a'

    d = 0  # Initialize a variable 'd' to keep track of the number of swaps made during sorting

    # Implement bubble sort algorithm to sort the list 'a' in ascending order
    for i in range(n):  # Iterate through each index of the list 'a'
        for j in range(n - 1, i, -1):  # Iterate through the list from the last index to the current index
            if a[j] < a[j - 1]:  # Check if the current element is smaller than the previous element
                # Swap the elements if they are in the wrong order
                a[j], a[j - 1] = a[j - 1], a[j]
                d += 1  # Increment the swap counter

    # Print the sorted list 'a'
    print(a[0], end='')  # Print the first element of the list
    for i in range(1, n):  # Iterate through the remaining elements of the list
        print(" ", a[i], end='')  # Print each element preceded by a space
    print()  # Print a newline character at the end of the line

    # Print the number of swaps made during sorting
    print(d)

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
