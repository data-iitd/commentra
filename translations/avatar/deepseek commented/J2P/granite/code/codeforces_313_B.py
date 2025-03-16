
import sys

class Fast:
    def sol(self, br, pw):
        # Read the input string
        s = br.readline().strip()

        # Initialize the cumulative array to store counts of consecutive identical characters
        cum = [0] * (len(s) + 1)
        cum[-1] = 0

        # Fill the cumulative array with counts of consecutive identical characters
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                cum[i] = cum[i - 1] + 1
            else:
                cum[i] = cum[i - 1]

        # Read the number of queries
        q = int(br.readline().strip())

        # Process each query
        for _ in range(q):
            l, r = map(int, br.readline().strip().split())

            # Calculate and print the result for the query
            pw.write(str(cum[r - 1] - cum[l - 2]) + '\n')

if __name__ == '__main__':
    br = sys.stdin
    pw = sys.stdout
    f = Fast()
    f.sol(br, pw)
    pw.close()
