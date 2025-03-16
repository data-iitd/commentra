import sys

class FastReader:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        if self.index < len(self.data):
            result = self.data[self.index]
            self.index += 1
            return result
        return None

    def next_int(self):
        return int(self.next())

def main():
    # Create a FastReader object to read input
    sc = FastReader()
    
    # Read an integer input
    x = sc.next_int()
    
    # Initialize a counter to keep track of the number of iterations
    count = 0
    
    # Store the initial value of x in a temporary variable
    tmp = x
    
    # Initialize x to 0 to start the loop
    x = 0
    
    # Loop until x becomes 360
    while x != 360:
        # Increment x by tmp
        x += tmp
        
        # If x exceeds 360, adjust it by subtracting 360
        if x > 360:
            x -= 360
        
        # Increment the counter
        count += 1
    
    # Print the final count
    print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
