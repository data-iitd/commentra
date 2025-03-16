import sys 
import math 

# Initialize FastReader for efficient input reading
class FastReader: 
    def __init__(self): 
        self.buf = sys.stdin.readline 
        self.buf = self.buf.buffer 
        self.buf.read = self.buf.raw.read 
        self.read = self.buf.read 
        self.flush = self.buf.flush 
        self.writable = self.buf.writable 
        self.write = lambda s: self.buf.write(s.encode("ascii")) 
        self.readline = lambda: self.buf.readline().decode("ascii").strip() 

# Initialize FastReader for efficient input reading
fr = FastReader() 

# Create a Scanner object for standard input
sc = Scanner(sys.stdin) 

# Create a PrintWriter object for output
o = PrintWriter(sys.stdout) 

# Read the number of pairs (n) and the minimum score (s)
n = sc.nextInt() 
s = sc.nextInt() 

# Initialize a variable to keep track of the maximum sum of pairs
max = 0

# Loop through each pair of integers
while n > 0: 
    # Read the two integers f and t
    f = sc.nextInt() 
    t = sc.nextInt() 
    # Update max if the sum of f and t is greater than the current max
    if max < f + t: 
        max = f + t 
    n -= 1

# Print the maximum value between max and s
o.println(max if max > s else s) 

# Close the PrintWriter
o.close() 

# END-OF-CODE
