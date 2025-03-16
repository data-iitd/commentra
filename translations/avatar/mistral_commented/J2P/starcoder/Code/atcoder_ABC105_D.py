
import sys

# Class to read input
class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.byteBuffer = bytearray()
        self.charBuffer = str()
        self.delimiter =''

    def read(self):
        while self.delimiter in self.charBuffer or not self.charBuffer:
            newBytes = self.stream.read(1024)
            if not newBytes:
                return None
            else:
                self.byteBuffer += newBytes
                self.charBuffer = self.charBuffer + self.byteBuffer.decode()
        token = self.charBuffer[:self.charBuffer.index(self.delimiter)]
        self.charBuffer = self.charBuffer[self.charBuffer.index(self.delimiter) + 1:]
        return token

    def readInt(self):
        return int(self.read())

    def readIntArray(self, n):
        return [int(self.read()) for _ in range(n)]

# Class to solve the problem
class TaskD:
    def solve(self, testNumber, in, out):
        # Read input
        n = in.readInt() # Number of elements in array a
        m = in.readInt() # Modulus value

        # Initialize data structures
        a = in.readIntArray(n) # Read array a
        dp = dict() # Hashmap to store intermediate results

        # Initialize variables
        ans = 0 # Answer variable
        base = 0 # Base value for hashmap key

        # Process each element in array a
        for i in range(n):
            # Update base value
            base = (base - a[i] % m + m) % m

            # Update hashmap with current base and its count
            dp[base + a[i] % m] = dp.get(base + a[i] % m, 0) + 1

            # Update answer variable
            ans += dp.get(base, 0)

        # Print the answer
        out.println(ans)

# Main method to start the program
if __name__ == '__main__':
    # Read input
    in = InputReader(sys.stdin)
    out = sys.stdout

    # Read test case number
    t = in.readInt()

    # Process each test case
    for i in range(t):
        # Initialize the solver
        solver = TaskD()

        # Solve the problem
        solver.solve(i + 1, in, out)

    # Close the output stream
    out.close()

