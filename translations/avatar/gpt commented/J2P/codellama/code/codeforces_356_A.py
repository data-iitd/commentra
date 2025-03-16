
# Initialize FastReader to read input efficiently
in = FastReader()

# Read the number of elements
n = in.nextInt()

# Create a TreeSet to keep track of available positions on the left
left = TreeSet()

# Initialize an array to store the answers
answer = [0] * n

# Populate the TreeSet with indices from 0 to n-1
for i in range(n):
    left.add(i)

# Read the number of queries
q = in.nextInt()

# Process each query
while q > 0:
    # Read the range [l, r] and the winning index
    l = in.nextInt() - 1
    r = in.nextInt() - 1
    win = in.nextInt()

    # Update the answer array for all positions in the range [l, r]
    while left.ceiling(l) != None and left.ceiling(l) <= r:
        curr = left.ceiling(l) # Get the smallest index >= l
        answer[curr] = win # Set the answer for this position
        left.remove(curr) # Remove this position from available positions

    # Mark the winning index as available again
    answer[win - 1] = 0
    left.add(win - 1) # Add the winning index back to available positions

    q -= 1

# Build the output string from the answer array
ans = ""
for i in range(n):
    ans += str(answer[i])

# Print the final answer
print(ans)

# FastReader class for efficient input reading
class FastReader:
    def __init__(self):
        self.br = open(0)

    # Method to read the next token as a String
    def next(self):
        while True:
            try:
                return self.st.nextToken()
            except:
                self.st = StringTokenizer(self.br.readline())

    # Method to read the next token as an integer
    def nextInt(self):
        return int(self.next())

    # Method to read the next token as a long
    def nextLong(self):
        return long(self.next())

    # Method to read the next token as a double
    def nextDouble(self):
        return float(self.next())

    # Method to read the next line as a String
    def nextLine(self):
        return self.br.readline()

# END-OF-CODE
