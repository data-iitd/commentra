import sys

# Main function as the entry point of the Python application
def main():
    # Read input from the standard input stream
    inp = sys.stdin.readline().strip().split()

    # Parse the first two elements of the array into integers n and m
    n = int(inp[0])
    m = int(inp[1])

    # Create a list ans to store the processed strings
    ans = []

    # Iterate through each string in the input
    for i in range(n):
        str_input = sys.stdin.readline().strip()  # Read a string from the input
        temp = []  # Initialize an empty list to build the string

        # Iterate through each character in the string
        for j in range(m):
            if str_input[j] == '-':  # If the character is a '-'
                temp.append('-')  # Append a '-' character to temp
            else:
                if (i + j) % 2 == 1:  # If the index i + j is odd
                    temp.append('W')  # Append 'W' character to temp
                else:
                    temp.append('B')  # Otherwise, append 'B' character to temp

        # Store the final string in the ans list
        ans.append(''.join(temp))

    # Iterate through each string in the ans list and print it to the standard output stream
    for result in ans:
        print(result)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
