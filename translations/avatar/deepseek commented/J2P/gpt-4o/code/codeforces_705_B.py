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
    t = scan.next_int()  # Read the number of test cases
    arr = [scan.next_int() for _ in range(t)]  # Read the elements of the array
    prev_winner = 0  # Initialize the previous winner variable

    for i in range(len(arr)):
        if arr[i] == 1:  # Check if the current element is 1
            if prev_winner == 0:  # If no previous winner, set the winner to 2
                prev_winner = 2

        if prev_winner == 2 or prev_winner == 0:  # Check if the previous winner is 2 or unset
            if (arr[i] - 1) % 2 == 0:  # Check if the condition for player 2 is met
                print(2)  # Print the winner
                prev_winner = 2  # Update the previous winner
            else:
                print(1)  # Print the winner
                prev_winner = 1  # Update the previous winner
        else:  # If the previous winner is 1
            if (arr[i] - 1) % 2 == 0:  # Check if the condition for player 1 is met
                print(1)  # Print the winner
                prev_winner = 1  # Update the previous winner
            else:
                print(2)  # Print the winner
                prev_winner = 2  # Update the previous winner

if __name__ == "__main__":
    scan = FastReader()
    t = 1
    while t > 0:
        solve()
        t -= 1

# <END-OF-CODE>
