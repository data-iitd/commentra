import sys

# Class to read input
class InputReader:
    # Constructor to initialize the InputReader object with the given input stream
    def __init__(self, stream):
        self.reader = stream
        self.tokenizer = None

    # Method to read a string token
    def next(self):
        while self.tokenizer == None or not self.tokenizer.hasMoreTokens():
            self.tokenizer = StringTokenizer(self.reader.readline())
        return self.tokenizer.nextToken()

    # Method to read an integer
    def nextInt(self):
        return int(self.next())

    # Method to read an array of integers
    def readArray(self, n):
        a = [0] * n
        for i in range(n):
            a[i] = self.nextInt()
        return a

# Class to solve the problem
class Solution:
    # Method to solve the problem using the given input and output objects
    def solve(self, in, out):
        n = in.nextInt() # Read the number of logs
        k = in.nextInt() # Read the number of days

        # Initialize the minimum and maximum possible days
        min = 1
        max = 1000000000 + 1000

        # Binary search to find the minimum day such that the number of days needed to cut the logs is greater than or equal to k
        while min < max:
            mid = (min + max) // 2 # Calculate the middle day
            if self.nei(mid, n, k): # If the number of days needed to cut the logs is greater than or equal to k
                max = mid # Narrow down the search space to the left
            else:
                min = mid + 1 # Narrow down the search space to the right

        # Print the minimum day as the output
        out.println(min)

    # Method to check if the number of days needed to cut the logs of given length is greater than or equal to k
    def nei(self, mid, n, k):
        daysNeeded = 0 # Initialize the days needed to zero

        # Iterate through all the logs and calculate the days needed to cut them
        for log in range(n):
            daysNeeded += (log + mid - 1) // mid # Calculate the days needed to cut the current log
            k -= daysNeeded # Subtract the days needed from the remaining days
            if k < 0: # If the remaining days are not sufficient to cut all the logs
                return False # Return false to indicate that the middle day is not the answer
        return True # If all the logs have been cut, return true to indicate that the middle day is the answer

# Main method to start the program
if __name__ == '__main__':
    in = InputReader(sys.stdin) # Initialize an InputReader object with standard input
    out = PrintWriter(sys.stdout) # Initialize a PrintWriter object with standard output
    sol = Solution() # Create a Solution object
    sol.solve(in, out) # Call the solve method of Solution object
    out.close() # Close the PrintWriter object

# 