# Main function starts here
def main():
    # Initialize variables N and X with user input
    N, X = map(int, input().split())

    # Create a list L to store the elements
    L = list(map(int, input().split()))

    # Initialize variable i and d to zero
    i = 0
    d = 0

    # Loop through the list L until the sum d exceeds X
    while i < N and d <= X:
        # Add the current element of list L to the sum d
        d += L[i]
        i += 1

    # Print the index of the last element in the list L that was added to the sum d
    print(i)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
