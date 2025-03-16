import sys

class TaskC:
    def solve(self, testNumber, in, out):
        # Read the number of strings
        n = in.readline()
        # Initialize an array to count occurrences of specific starting letters
        cnt = [0] * 5
        # Process each string input
        for i in range(0, n):
            str = in.readline()
            # Increment the count based on the first character of the string
            if str[0] == 'M':
                cnt[0] += 1
            elif str[0] == 'A':
                cnt[1] += 1
            elif str[0] == 'R':
                cnt[2] += 1
            elif str[0] == 'C':
                cnt[3] += 1
            elif str[0] == 'H':
                cnt[4] += 1
        # Calculate the result based on combinations of counts
        res = cnt[0] * cnt[1] * cnt[2] + \
              cnt[0] * cnt[1] * cnt[3] + \
              cnt[0] * cnt[1] * cnt[4] + \
              cnt[0] * cnt[2] * cnt[3] + \
              cnt[0] * cnt[2] * cnt[4] + \
              cnt[0] * cnt[3] * cnt[4] + \
              cnt[1] * cnt[2] * cnt[3] + \
              cnt[1] * cnt[2] * cnt[4] + \
              cnt[1] * cnt[3] * cnt[4] + \
              cnt[2] * cnt[3] * cnt[4]
        # Output the result
        out.write(str(res) + "\n")

if __name__ == "__main__":
    # Set up input and output streams
    in = sys.stdin
    out = sys.stdout
    # Create an instance of TaskC to solve the problem
    solver = TaskC()
    # Call the solve method with test number 1
    solver.solve(1, in, out)
    # Close the output stream
    out.close()

