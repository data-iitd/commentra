import sys

class Scanner:
    def __init__(self):
        self.buffer = sys.stdin.read().split()
        self.index = 0

    def next_int(self):
        value = int(self.buffer[self.index])
        self.index += 1
        return value

def main():
    sc = Scanner()

    # Read the number of elements
    n = sc.next_int()
    
    # Initialize a list to hold the float values
    arr = []
    
    # Read each integer and convert it to float, then store in the list
    for _ in range(n):
        arr.append(float(sc.next_int()))
    
    # Sort the list of float values
    arr.sort()
    
    # Initialize a variable to keep track of the running average
    prev = arr[0]
    
    # Iterate through the sorted list to calculate the average
    for i in range(1, len(arr)):
        prev = (prev + arr[i]) / 2

    # Print the final average
    print(prev)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
