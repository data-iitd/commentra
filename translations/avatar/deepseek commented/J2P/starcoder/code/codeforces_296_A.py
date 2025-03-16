
# Importing necessary I/O libraries for file handling and other operations
import sys
import io

# Importing the StringTokenizer class for tokenizing strings
from java.util import StringTokenizer

# Creating a class called Main to encapsulate the entire code
class Main:
    # Creating a method called main to encapsulate the code to be executed
    @staticmethod
    def main(args):
        # Creating an object of the InputReader class to read input from stdin
        in = InputReader(sys.stdin)
        # Creating an object of the PrintWriter class to write output to stdout
        out = PrintWriter(sys.stdout)
        # Creating an object of the Task class
        solver = Task()
        # Calling the solve method of the Task class to solve the problem
        solver.solve(in, out)
        # Closing the output stream
        out.close()

# Creating a class called Task to encapsulate the code to be executed
class Task:
    # Creating a method called solve to encapsulate the code to be executed
    def solve(self, in, out):
        # Reading the number of elements
        n = in.nextInt()
        # Initializing an array to count occurrences
        array = [0] * 1001
        # Looping through each element
        for i in range(n):
            # Reading the current element
            index = in.nextInt()
            # Incrementing the count of the current element
            array[index] += 1
        # Initializing the maximum count to -1
        countMax = -1
        # Looping through the array to find the maximum count
        for i in range(1, len(array)):
            # Updating the maximum count if necessary
            if countMax < array[i]:
                countMax = array[i]
        # Checking if n is even
        if n % 2 == 0:
            # Checking if the maximum count is less than or equal to half of n
            if countMax <= n // 2:
                # Printing "YES" if the condition is met
                out.println("YES")
            # Printing "NO" if the condition is not met
            else:
                out.println("NO")
        # If n is odd
        else:
            # Checking if the maximum count is less than or equal to half of n rounded up
            if countMax <= (n + 1) // 2:
                # Printing "YES" if the condition is met
                out.println("YES")
            # Printing "NO" if the condition is not met
            else:
                out.println("NO")

# Creating a class called InputReader to read input from stdin
class InputReader:
    # Creating a constructor to initialize the stream
    def __init__(self, stream):
        # Declaring a BufferedReader object
        self.reader = io.BufferedReader(io.InputStreamReader(stream), 32768)
        # Declaring a StringTokenizer object
        self.tokenizer = None

    # Creating a method to read the next token
    def next(self):
        # Initializing the next token to None
        nextToken = None
        # Checking if there are more tokens
        while self.tokenizer == None or not self.tokenizer.hasMoreElements():
            # Reading the next line
            line = None
            try:
                line = self.reader.readLine()
            # Printing the stack trace if an error occurs
            except Exception as e:
                e.printStackTrace()
            # Initializing the StringTokenizer if the line is not empty
            if line!= None:
                self.tokenizer = StringTokenizer(line)
        # Returning the next token
        return self.tokenizer.nextToken()

    # Creating a method to read the next token as an integer
    def nextInt(self):
        # Returning the next token parsed as an integer
        return int(self.next())

    # Creating a method to read the next token as a long
    def nextLong(self):
        # Returning the next token parsed as a long
        return long(self.next())

    # Creating a method to read the next token as a double
    def nextDouble(self):
        # Returning the next token parsed as a double
        return float(self.next())

    # Creating a method to read the next line
    def nextLine(self):
        # Initializing the next line to None
        nextLine = None
        # Reading the next line
        try:
            nextLine = self.reader.readLine()
        # Printing the stack trace if an error occurs
        except Exception as e:
            e.printStackTrace()
        # Returning the read line
        return nextLine

# Creating a class called PrintWriter to write output to stdout
class PrintWriter:
    # Creating a constructor to initialize the stream
    def __init__(self, stream):
        # Declaring a PrintWriter object
        self.writer = io.PrintWriter(stream, True)

    # Creating a method to print a line
    def println(self, x):
        # Printing the line
        self.writer.println(x)

    # Creating a method to close the stream
    def close(self):
        # Closing the stream
        self.writer.close()

# Creating a method to execute the code
if __name__ == '__main__':
    # Creating an object of the Main class
    main = Main()
    # Calling the main method of the Main class to execute the code
    main.main(sys.argv)

# 