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

    def next_long(self):
        return int(self.next())  # Python's int can handle long values

    def next_double(self):
        return float(self.next())

    def next_line(self):
        return self.data[self.index] if self.index < len(self.data) else None

scan = FastReader()  # Creating an instance of FastReader

def solve():
    t = scan.next_int()  # Reading the number of test cases
    arr = [scan.next_int() for _ in range(t)]  # Reading the input into a list

    global prev_winner
    for i in range(len(arr)):  # Iterating through the array
        if arr[i] == 1:  # Checking if the current element is 1
            if prev_winner == 0:  # If the previous winner was 0
                prev_winner = 2  # Update the 'prev_winner' variable to 2

            if (i - 1) % 2 == 0:  # Checking the parity of the current element's index
                print(2 if prev_winner == 0 else 1)  # Printing the output based on the 'prev_winner' value
                prev_winner = 2 if prev_winner == 0 else 1  # Updating the 'prev_winner' variable for the next iteration

prev_winner = 0  # Initializing the 'prev_winner' variable to 0

if __name__ == "__main__":
    t = 1  # Initializing the test case counter
    while t > 0:  # Running the solution process for all test cases
        solve()
        t -= 1

# <END-OF-CODE>
