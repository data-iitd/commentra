
import sys

# Function out is used to print the output to the console
def out(*x):
    # print(*x)
    pass

# Initialize scanner for reading input from stdin
sc = bufio.Scanner(sys.stdin.buffer)

# Function nextInt reads an integer from the input
def nextInt():
    sc.scan()
    return int(sc.text())

# Function nextString reads a string from the input
def nextString():
    sc.scan()
    return sc.text()

# Main function starts here
def main():
    # Initialize scanner for reading input from stdin
    sc.buffer.readline()

    # Read number of data points N from the input
    N = nextInt()

    # Read number of queries L from the input
    L = nextInt()

    # Initialize a list of strings named s with capacity N
    s = [""] * N

    # Read data points X from the input and store them in the list s
    for i in range(N):
        s[i] = nextString()

    # Print the number of data points N, number of queries L, and the list s
    out(N, L, s)

    # Sort the list s in ascending order
    s.sort()

    # Initialize an empty string ans to store the concatenated X values
    ans = ""

    # Iterate through the list s and concatenate X values to the string ans
    for i in range(N):
        ans += s[i]

    # Print the concatenated string ans to the console
    print(ans)

# Call the main function to start the program
if __name__ == "__main__":
    main()

