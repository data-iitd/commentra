
import sys
# Import the sys module to read input from stdin and write output to stdout.

class BABC:
    def solve(self, testNumber, in, out):
        s = in.next().replace("BC", "D")
        # Read the input string and replace all occurrences of "BC" with "D".
        cnt = 0
        tmp = 0
        for i in range(len(s)):
            if s[i] == 'A':
                tmp += 1
            elif s[i] == 'D':
                cnt += tmp
            else:
                tmp = 0
        out.write(str(cnt) + "\n")
        # Print the final count.

if __name__ == "__main__":
    solver = BABC()
    # Create an instance of the BABC class.
    solver.solve(1, sys.stdin, sys.stdout)
    # Call the solve method of the BABC class.
# 