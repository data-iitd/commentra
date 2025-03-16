import sys

class Task:
    def solve(self, in_stream, out_stream):
        # Read the number of elements
        n = int(in_stream.readline())

        # Initialize an array to count occurrences of each index (up to 1000)
        array = [0] * 1001

        # Read n integers and count their occurrences
        for i in range(n):
            index = int(in_stream.readline())
            array[index] += 1

        # Determine the maximum count of any index
        count_max = -1
        for i in range(1, len(array)):
            if count_max < array[i]:
                count_max = array[i]

        # Check if the maximum count is within allowed limits based on n being even or odd
        if n % 2 == 0:
            # For even n, check if the maximum count is less than or equal to n/2
            if count_max <= n / 2:
                out_stream.write("YES\n")
            else:
                out_stream.write("NO\n")
        else:
            # For odd n, check if the maximum count is less than or equal to n/2 + 1
            if count_max <= n / 2 + 1:
                out_stream.write("YES\n")
            else:
                out_stream.write("NO\n")

if __name__ == "__main__":
    # Set up input and output streams
    in_stream = sys.stdin
    out_stream = sys.stdout

    # Create an InputReader to read input from the input stream
    in_reader = InputReader(in_stream)

    # Create a PrintWriter to write output to the output stream
    out_writer = PrintWriter(out_stream)

    # Instantiate the Task class to solve the problem
    solver = Task()

    # Call the solve method to process the input and produce output
    solver.solve(in_reader, out_writer)

    # Close the PrintWriter to flush and release resources
    out_writer.close()

class InputReader:
    def __init__(self, stream):
        self.reader = stream.buffer
        self.tokenizer = None

    def next(self):
        # Read a new line if the tokenizer is empty
        while self.tokenizer is None or not self.tokenizer.hasMoreTokens():
            self.tokenizer = self.reader.readline().decode().split()
        return self.tokenizer.nextToken()

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return long(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        str = ""
        try:
            str = self.reader.readLine().decode()
        except:
            pass
        return str

# 