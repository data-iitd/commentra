
import sys

# Set log flags to show the file name and line number for log messages
import logging
logging.basicConfig(format='%(filename)s:%(lineno)s: %(message)s', level=logging.DEBUG)

# Initialize a new scanner to read input
def newScanner():
    return Scanner(sys.stdin)

# scanner struct to handle buffered input reading
class Scanner:
    def __init__(self, r):
        self.r = r
        self.buf = []
        self.p = 0

    def next(self):
        self.pre() # Ensure there's data to read
        start = self.p # Mark the start position
        while self.p < len(self.buf):
            if self.buf[self.p] =='': # Stop at space
                break
            self.p += 1
        result = ''.join(self.buf[start:self.p]) # Extract the token
        self.p += 1 # Move past the space
        return result # Return the token

    def nextLine(self):
        self.pre() # Ensure there's data to read
        start = self.p # Mark the start position
        self.p = len(self.buf) # Move to the end of the buffer
        return ''.join(self.buf[start:]) # Return the line

    def nextInt(self):
        v = int(self.next()) # Convert the next token to an integer
        return v # Return the integer

    def pre(self):
        if self.p >= len(self.buf): # If the current position is at or beyond the buffer length
            self.readLine() # Read a new line into the buffer
            self.p = 0 # Reset the position to the start of the buffer

    def readLine(self):
        self.buf = [] # Clear the buffer
        while True:
            l = self.r.readline() # Read a line
            if not l: # If the line is empty
                break # Exit the loop
            self.buf.extend(l) # Append the line to the buffer

# Initialize variables to store the category indices of x and y
xt = yt = -1

# Define a 2D array where each sub-array represents a category of numbers
a = [[1, 3, 5, 7, 8, 10, 12], [4, 6, 9, 11], [2]]

# Read two integers from input
x = int(input())
y = int(input())

# Iterate through the categories to find the indices of x and y
for i, t in enumerate(a):
    for n in t:
        # Check if the current number matches x
        if x == n:
            xt = i # Store the category index for x
        # Check if the current number matches y
        if y == n:
            yt = i # Store the category index for y

# Compare the category indices of x and y and print the result
if xt == yt:
    print("Yes") # x and y belong to the same category
else:
    print("No")  # x and y belong to different categories

