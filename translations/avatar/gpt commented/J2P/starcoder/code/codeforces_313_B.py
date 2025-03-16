import sys

class Fast:
    def sol(self, br, pw):
        # Read the first line of input and tokenize it to get the string
        s = br.readline().split()[0]

        # Initialize a cumulative array to count consecutive characters
        cum = [0] * (len(s) + 1)
        cum[0] = cum[len(s)] = 0

        # Fill the cumulative array with counts of consecutive characters
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                cum[i] = cum[i - 1] + 1
            else:
                cum[i] = cum[i - 1]

        # Read the number of queries from the input
        q = int(br.readline())

        # Process each query
        while q > 0:
            # Read the range for the query
            l, r = map(int, br.readline().split())

            # Calculate and print the result for the current query
            pw.write(str(cum[r] - cum[l - 1]) + '\n')

            q -= 1

if __name__ == "__main__":
    # Create a BufferedReader to read input from the standard input stream
    br = sys.stdin

    # Create a PrintWriter to output results to the standard output stream
    pw = sys.stdout

    # Create an instance of the Fast class to process the input
    f = Fast()

    # Call the solution method to handle the input and produce output
    f.sol(br, pw)

    # Close the PrintWriter to flush the output
    pw.close()

