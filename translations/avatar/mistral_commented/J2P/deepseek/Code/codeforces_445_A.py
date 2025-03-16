import sys

# Read input from the standard input stream using a sys.stdin.readline object
def read_input():
    return sys.stdin.readline().strip()

# Main function as the entry point of the Python application
def main():
    # Read the first line of input and split it into an array of strings
    inp = read_input().split()

    # Parse the first two elements of the array into integers n and m
    n = int(inp[0])
    m = int(inp[1])

    # Create an array ans of size n to store the processed strings
    ans = []

    # Iterate through each string in the input
    for i in range(n):
        str = read_input()  # Read a string from the input
        temp = ""  # Initialize an empty string

        # Iterate through each character in the string
        for j in range(m):
            if str[j] == '-':  # If the character is a '-'
                temp += "-"  # Append '-' character to temp
            else:
                if (i + j) % 2 == 1:  # If the index i + j is odd
                    temp += "W"  # Append 'W' character to temp
                else:
                    temp += "B"  # Otherwise, append 'B' character to temp

        # Store the final string in the ans array using the index i
        ans.append(temp)

    # Iterate through each string in the ans array and print it to the standard output stream
    for i in range(n):
        print(ans[i])

# Call the main function
if __name__ == "__main__":
    main()
