
import sys

def solve(testNumber, inp, out):
    # Method to solve the problem

    n = int(inp.readline()) # Read the number of test cases

    cnt = [0] * 5 # Initialize an array of size 5 to store counts

    for i in range(n):
        # Loop through each test case

        str = inp.readline().strip() # Read a string from input

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

    out.write(str(res) + '\n') # Write the result to the output

if __name__ == '__main__':
    # Main method to start the program

    solve(1, sys.stdin, sys.stdout) # Call the solve method with test number, input scanner, and output print writer

# 