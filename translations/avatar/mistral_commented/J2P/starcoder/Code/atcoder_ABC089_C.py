
import sys # For reading input from stdin
import math # For using mathematical functions

# Class to solve the problem
class TaskC:
    # Method to solve the problem
    def solve(self, testNumber, in, out):
        # Read the number of test cases
        n = int(in.readline())

        cnt = [0] * 5 # Initialize an array of size 5 to store counts

        for i in range(0, n):
            # Loop through each test case

            str = in.readline() # Read a string from input

            if str[0] == 'M':
                # If the first character of the string is 'M', increment the count of 'M'
                cnt[0] += 1
            elif str[0] == 'A':
                # If the first character of the string is 'A', increment the count of 'A'
                cnt[1] += 1
            elif str[0] == 'R':
                # If the first character of the string is 'R', increment the count of 'R'
                cnt[2] += 1
            elif str[0] == 'C':
                # If the first character of the string is 'C', increment the count of 'C'
                cnt[3] += 1
            elif str[0] == 'H':
                # If the first character of the string is 'H', increment the count of 'H'
                cnt[4] += 1

        res = cnt[0] * cnt[1] * cnt[2] + # Calculate the first product
                cnt[0] * cnt[1] * cnt[3] + # Calculate the second product
                cnt[0] * cnt[1] * cnt[4] + # Calculate the third product
                cnt[0] * cnt[2] * cnt[3] + # Calculate the fourth product
                cnt[0] * cnt[2] * cnt[4] + # Calculate the fifth product
                cnt[0] * cnt[3] * cnt[4] + # Calculate the sixth product
                cnt[1] * cnt[2] * cnt[3] + # Calculate the seventh product
                cnt[1] * cnt[2] * cnt[4] + # Calculate the eighth product
                cnt[1] * cnt[3] * cnt[4] + # Calculate the ninth product
                cnt[2] * cnt[3] * cnt[4] # Calculate the tenth product

        out.write(str(res) + "\n") # Write the result to the output

# Main method to start the program
if __name__ == "__main__":
    # Create an instance of the TaskC class
    solver = TaskC()

    # Read the number of test cases
    testNumber = int(sys.stdin.readline())

    # Read the input from stdin
    in = sys.stdin

    # Write the output to stdout
    out = sys.stdout

    # Solve the problem
    solver.solve(testNumber, in, out)

