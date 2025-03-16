# Importing necessary Python libraries
import sys
import io

# Creating FastReader class to read input
class FastReader:
    def __init__(self):
        self.reset()
        self.buffer = io.BytesIO(sys.stdin.buffer.read())

    def reset(self):
        self.buffer.seek(0)
        self.buffer.truncate()

    def readline(self):
        return self.buffer.readline().decode('utf-8')

    def read(self):
        return self.buffer.read().decode('utf-8')

    def next(self):
        self.tok = self.read().strip()
        return self.tok

    def nextInt(self):
        self.tok = self.read().strip()
        return int(self.tok)

    def nextLong(self):
        self.tok = self.read().strip()
        return int(self.tok)

    def nextDouble(self):
        self.tok = self.read().strip()
        return float(self.tok)

# Creating Main class
class Main:
    # Creating main method
    def main(self):
        # Creating FastReader object to read input
        f = FastReader()

        # Reading the first integer input
        x = f.nextInt()

        # Initializing count variable to 0
        count = 0

        # Initializing temporary variable tmp with the value of x
        tmp = x

        # Setting x to 0
        x = 0

        # Starting a while loop that runs until x is equal to 360
        while (x!= 360):

            # Adding the value of tmp to x
            x = x + tmp

            # If x is greater than 360, then subtract 360 from it
            if (x > 360):
                x = x - 360

            # Incrementing the count variable
            count = count + 1

        # Printing the value of count to the console
        print(count)

# Creating object of Main class
if __name__ == '__main__':
    obj = Main()
    obj.main()

# 