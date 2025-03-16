# Importing necessary Python libraries
import sys

# Main class starts here
class Main:

    # Main method starts here
    def main(self):

        # Creating FastReader object to read input
        sc = FastReader()

        # Creating PrintWriter object to write output
        pw = PrintWriter(sys.stdout)

        # Reading the first integer input
        x = sc.nextInt()

        # Initializing count variable to 0
        count = 0

        # Initializing temporary variable tmp with the value of x
        tmp = x

        # Setting x to 0
        x = 0

        # Starting a while loop that runs until x is equal to 360
        while x != 360:

            # Adding the value of tmp to x
            x = x + tmp

            # If x is greater than 360, then subtract 360 from it
            if x > 360:
                x = x - 360

            # Incrementing the count variable
            count += 1

        # Printing the value of count to the console using PrintWriter
        pw.println(count)

        # Closing the PrintWriter and FastReader objects
        pw.close()
        sc.close()

    # FastReader class starts here
    class FastReader:

        # Creating BufferedReader object to read input
        br = BufferedReader(InputStreamReader(sys.stdin))

        # Creating StringTokenizer object to tokenize input
        st = StringTokenizer(br.readLine())

        # Constructor method initializes BufferedReader object
        def __init__(self):
            self.br = BufferedReader(InputStreamReader(sys.stdin))

        # Method to read a string token
        def next(self):
            while self.st == None or not self.st.hasMoreElements():
                try:
                    self.st = StringTokenizer(self.br.readLine())
                except IOException as e:
                    e.printStackTrace()
            return self.st.nextToken()

        # Method to read an integer input
        def nextInt(self):
            return int(self.next())

        # Method to read a long integer input
        def nextLong(self):
            return long(self.next())

        # Method to read a double input
        def nextDouble(self):
            return float(self.next())

        # Method to read a full line of input
        def nextLine(self):
            str = ""
            try:
                str = self.br.readLine()
            except IOException as e:
                e.printStackTrace()
            return str

# Main class ends here

# Main method starts here
if __name__ == "__main__":
    Main().main()

# Main method ends here

# END-OF-CODE
