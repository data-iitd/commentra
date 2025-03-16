# Define a function to read input and output sorted strings
def main():
    # Read the number of strings (N) and the length of each string (L)
    N, L = map(int, input().split())

    # Input the strings from the user
    S = [input().strip() for _ in range(N)]

    # Sort the array of strings in lexicographical order
    S.sort()

    # Output the sorted strings
    for string in S:
        print(string, end='')

    # Print a newline at the end of the output
    print()

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
