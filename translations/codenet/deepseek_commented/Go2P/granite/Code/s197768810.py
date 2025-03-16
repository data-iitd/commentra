
import sys

# Initialize a global scanner to read input efficiently
sc = bufio.Scanner(sys.stdin)

# readInt reads a single integer from the standard input
def readInt():
    sc.scan()
    return int(sc.text())

# readFloat64 reads a single float64 from the standard input
def readFloat64():
    sc.scan()
    return float(sc.text())

# readString reads a single string from the standard input
def readString():
    sc.scan()
    return sc.text()

# Main function to execute the program
def main():
    # Set the scanner to read words instead of lines
    sc.wordchars += '.1234567890'
    sc.whitespace = sc.wordchars +'\t\n'

    # Read two integers n and m from the input
    n, m = readInt(), readInt()

    # Initialize a list to hold m integers
    a = []
    sum = 0

    # Read m integers into the list a and calculate their sum
    for i in range(m):
        a.append(readInt())
        sum += a[i]

    # Check if the sum of integers exceeds n
    if sum > n:
        # Print -1 if the sum exceeds n and exit
        print(-1)
        return

    # Print the difference between n and the sum if it's within bounds
    print(n - sum)

# Execute the main function
if __name__ == "__main__":
    main()

