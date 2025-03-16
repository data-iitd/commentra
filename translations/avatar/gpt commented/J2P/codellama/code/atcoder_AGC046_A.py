
# Import the required modules
import sys
import math

# Create a FastReader object to read input efficiently
class FastReader:
    def __init__(self):
        self.br = sys.stdin
        self.st = None

    def next(self):
        # Continue reading until there are more tokens available
        while self.st == None or not self.st.hasMoreElements():
            try:
                # Read a line and tokenize it
                self.st = sys.stdin.readline().split()
            except:
                pass
        # Return the next token
        return self.st.pop(0)

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return long(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        str = ""
        try:
            str = sys.stdin.readline()
        except:
            pass
        return str

# Create a FastReader object to read input efficiently
sc = FastReader()

# Read an integer input from the user
x = sc.nextInt()

# Initialize a counter to keep track of the number of rotations
count = 0

# Store the original value of x for later use
tmp = x

# Reset x to 0 for the rotation calculation
x = 0

# Loop until x completes a full rotation (360 degrees)
while x != 360:
    # Increment x by the original input value
    x = x + tmp

    # If x exceeds 360, wrap it around by subtracting 360
    if x > 360:
        x = x - 360

    # Increment the count of rotations
    count += 1

# Output the total number of rotations needed to reach 360 degrees
print(count)

# END-OF-CODE
