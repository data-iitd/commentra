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
    # Create a FastReader object to read input efficiently
    sc = FastReader()
    
    # Read an integer input from the user
    x = sc.next_int()
    
    # Initialize a counter to keep track of the number of rotations
    count = 0
    # Store the original value of x for later use
    tmp = x
    # Reset x to 0 for the rotation calculation
    x = 0
    
    # Loop until x completes a full rotation (360 degrees)
    while x != 360:
        # Increment x by the original input value
        x += tmp
        # If x exceeds 360, wrap it around by subtracting 360
        if x > 360:
            x -= 360
        # Increment the count of rotations
        count += 1
    
    # Output the total number of rotations needed to reach 360 degrees
    print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
