
# Package main is the entry point of the program
def main():
    # Get the number of elements in the input array
    n = int(input())
    # Get the input array
    ls = list(map(int, input().split()))
    # Create a reversed copy of the input array
    lsRev = ls[::-1]
    # Sort the input array in ascending order
    ls.sort()
    # Sort the reversed copy of the array in descending order
    lsRev.sort(reverse=True)

    # Initialize the answer variable
    ans = 0
    # Iterate through all pairs of elements in the array
    for i in range(n):
        for j in range(i + 1, n):
            # Find the minimum and maximum elements of the current pair
            p, q = min(ls[i], ls[j]), max(ls[i], ls[j])
            # Calculate the difference between the maximum and minimum elements
            x, y = q - p, q + p
            # Find the indices of the elements greater than x and less than y in the sorted array and reversed array respectively
            l = bisect_left(ls, x)
            r = n - bisect_right(lsRev, y)
            # Calculate the sum of the difference between the indices of the greater elements in the sorted array and reversed array
            sum = r - l
            # Check if the current pair lies within the range [l, r]
            if i >= l and i <= r:
                sum -= 1
            if j >= l and j <= r:
                sum -= 1
            # Ensure that the sum is not negative
            sum = max(0, sum)
            # Add the sum to the answer variable
            ans += sum
    # Divide the answer by 3 and print it
    ans //= 3
    print(ans)

# min returns the minimum of two integers
def min(a, b):
    if a < b:
        return a
    return b

# max returns the maximum of two integers
def max(a, b):
    if a > b:
        return a
    return b

# -----------------------------------------

# Initialize some variables for reading and writing input/output
#buf = 200001
#scanner = bufio.Scanner(sys.stdin)
#scanner.buffer(buf, buf)
#scanner.split(bufio.ScanWords)
#writer = bufio.Writer(sys.stdout)

# main is the entry point of the program
def main():
    # Call the main function
    main()
    # Flush the writer buffer
    writer.flush()

# getInt reads an integer from the standard input
def getInt():
    # Read an integer from the standard input
    i = int(input())
    # Return the input integer
    return i

# getIntSlice reads an array of integers from the standard input
def getIntSlice(n):
    # Allocate memory for the array
    is = [0] * n
    # Read each element of the array from the standard input
    for i in range(n):
        is[i] = getInt()
    # Return the array
    return is

# getString reads a string from the standard input
def getsString():
    # Read a string from the standard input
    s = input()
    # Return the input string
    return s

# puts writes the given arguments to the standard output, followed by a newline character
def puts(a):
    # Write the arguments to the writer buffer
    writer.write(str(a) + '\n')

# -----------------------------------------

# END-OF-CODE
