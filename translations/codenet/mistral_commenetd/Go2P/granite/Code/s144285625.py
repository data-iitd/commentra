

# Initializing scanner for reading input from stdin
sc = bufio.NewScanner(os.Stdin)

# Function to read next integer from input
def nextInt():
    # Reading next token as a string
    sc.scan()
    # Converting the string to integer
    return int(sc.text())

# Main function
def main():
    # Initializing scanner for reading input from stdin
    sc.split(bufio.ScanWords)

    # Reading the number of elements in the array
    n = nextInt()

    # Allocating memory for the array
    ar = [0] * (3 * n)

    # Reading elements of the array
    for i in range(3 * n):
        # Reading next integer and storing it in the array
        ar[i] = nextInt()

    # Sorting the array in ascending order
    ar.sort()

    # Calculating the sum of elements at index 3n-2i-1 in the sorted array
    sum = 0
    for i in range(n):
        # Adding the element at index 3n-2i-1 to the sum
        sum += ar[3 * n - (i + 1) * 2]

    # Printing the result
    print(sum)

