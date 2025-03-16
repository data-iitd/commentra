

import sys

# Initialize FastReader for reading input
def main():
    sc = FastReader()
    out = PrintWriter(sys.stdout)

    # Read the number of test cases
    n = sc.nextInt()

    # Initialize an array 'a' to store the frequency of each number
    a = [0] * 33

    # Read each test case and update the frequency of the number in the array 'a'
    for i in range(n):
        num = sc.nextInt() # Read a number
        index = rec(num)   # Get the index of the number in the array 'a'
        a[index] += 1       # Increment the frequency of the number in the array 'a'

    # Calculate the answer and print it
    answer = 0
    for i in range(len(a)):
        summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1) # Calculate the sum of squares of numbers up to the current number
        answer += summ                           # Add the sum to the answer
    out.println(int(answer))                    # Print the answer as an integer
    out.close()                                   # Close the PrintWriter

# A helper method to get the index of a number in the array 'a'
def rec(x):
    answer = 0

    # Calculate the index of the number in the array 'a' by counting the number of set bits in the binary representation of the number
    for k in range(31, -1, -1):
        if (x & (1 << k))!= 0: # If the k-th bit is set
            answer += 1           # Increment the answer

    return answer

# A custom InputReader class for reading input efficiently
class FastReader:
    def __init__(self):
        self.br = BufferedReader(InputStreamReader(sys.stdin))
        self.st = StringTokenizer("")

    # Read a string token
    def next(self):
        while not self.st.hasMoreTokens():
            self.st = StringTokenizer(self.br.readLine())
        return self.st.nextToken()

    # Read an integer
    def nextInt(self):
        return int(self.next())

    # Read a long integer
    def nextLong(self):
        return long(self.next())

    # Read a double
    def nextDouble(self):
        return double(self.next())

    # Read a line
    def nextLine(self):
        line = ""
        try:
            line = self.br.readLine()
        except:
            pass
        return line

print("