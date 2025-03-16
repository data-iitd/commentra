import sys

class FastReader:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        value = self.data[self.index]
        self.index += 1
        return value

    def next_int(self):
        return int(self.next())

def solve():
    # Read the number of elements in the array
    t = scan.next_int()
    arr = [scan.next_int() for _ in range(t)]
    
    prev_winner = 0  # Variable to track the previous winner
    
    # Iterate through the array to determine the winner for each element
    for i in range(len(arr)):
        # Check if the current element is 1
        if arr[i] == 1:
            # If the previous winner is 0, set the previous winner to 2
            if prev_winner == 0:
                prev_winner = 2
        
        # Determine the winner based on the previous winner and the current element
        if prev_winner == 2 or prev_winner == 0:
            # If the previous winner is 2 or 0, check the parity of (arr[i] - 1)
            if (arr[i] - 1) % 2 == 0:
                print(2)  # Print winner 2
                prev_winner = 2  # Update previous winner
            else:
                print(1)  # Print winner 1
                prev_winner = 1  # Update previous winner
        else:
            # If the previous winner is 1, check the parity of (arr[i] - 1)
            if (arr[i] - 1) % 2 == 0:
                print(1)  # Print winner 1
                prev_winner = 1  # Update previous winner
            else:
                print(2)  # Print winner 2
                prev_winner = 2  # Update previous winner

# Create an instance of FastReader for input
scan = FastReader()

def main():
    t = 1  # Number of test cases (currently set to 1)
    while t > 0:
        solve()  # Call the solve method for processing
        t -= 1

if __name__ == "__main__":
    main()

# <END-OF-CODE>
