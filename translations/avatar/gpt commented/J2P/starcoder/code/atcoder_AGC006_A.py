import sys

# Define a constant for the maximum size of the arrays
N = 200 + 10
# Array to store the failure function values
f = [0] * N
# Array to store the concatenated strings
b = [0] * N

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

# Main function
def main():
    # Create an input reader and output writer
    in = InputReader(sys.stdin)
    out = PrintWriter(sys.stdout)

    # Read the length of the strings
    n = in.nextInt()
    # Read the two strings
    s1 = in.next()
    str = in.next()
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
    out.println(2 * n - len)
    out.flush() # Ensure all output is written

# Class to handle input reading
class InputReader:
    def __init__(self, stream):
        self.reader = BufferedReader(InputStreamReader(stream), 32768)
        self.tokenizer = None

    # Method to read the next token from input
    def next(self):
        # Read a new line if the tokenizer is null or has no more tokens
        while self.tokenizer == None or not self.tokenizer.hasMoreTokens():
            try:
                self.tokenizer = StringTokenizer(self.reader.readLine())
            except IOException as e:
                raise RuntimeException(e)
        return self.tokenizer.nextToken()

    # Method to read the next integer from input
    def nextInt(self):
        return Integer.parseInt(self.next())

# Main execution
if __name__ == '__main__':
    main()

