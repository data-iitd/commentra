
import sys

# Define a constant for the maximum size of the arrays
N = 200 + 10
# Array to store the failure function values
f = [0] * (N)
# Array to store the concatenated strings
b = [0] * (N)

# Function to compute the failure function for the KMP algorithm
def getFail(b, m):
    j = 0 # Initialize j to track the length of the previous longest prefix suffix
    f[0] = f[1] = 0 # Base cases for the failure function

    # Loop through the string to fill the failure function
    for i in range(2, m + 1):
        # Adjust j until we find a match or j becomes 0
        while j > 0 and b[j + 1]!= b[i]:
            j = f[j]
        # If there is a match, increment j
        if b[j + 1] == b[i]:
            j += 1
        # Set the failure function value for the current position
        f[i] = j

# Main function to read input and compute the result
def main():
    # Create an input reader and output writer
    in_file = sys.stdin
    out_file = sys.stdout

    # Read the length of the strings
    n = int(in_file.readline())
    # Read the two strings
    s1 = in_file.readline().strip()
    str = in_file.readline().strip()
    cnt = 0

    # Concatenate the second string into the character array
    for i in range(n):
        b[cnt + 1] = str[i]
        cnt += 1
    # Concatenate the first string into the character array
    for i in range(n):
        b[cnt + 1] = s1[i]
        cnt += 1

    # Compute the failure function for the concatenated strings
    getFail(b, cnt)

    # Calculate the length of the longest prefix which is also a suffix
    len = min(f[cnt], min(n, n))
    # Output the result based on the calculated length
    out_file.write(str(2 * n - len) + '\n')

# Call the main function to execute the program
if __name__ == '__main__':
    main()

