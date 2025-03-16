
# FastReader class to handle fast input
class FastReader:
    def __init__(self):
        self.br = open(0)
        self.st = None

    # Method to read the next token from input
    def next(self):
        # Read new line if no tokens are available
        while self.st == None or not self.st.hasMoreElements():
            try:
                self.st = StringTokenizer(self.br.readline())
            except IOException as e:
                e.printStackTrace()

        return self.st.nextToken()

    # Method to read the next integer from input
    def nextInt(self):
        return int(self.next())

    # Method to read the next long from input
    def nextLong(self):
        return long(self.next())

    # Method to read the next double from input
    def nextDouble(self):
        return double(self.next())

    # Method to read the next line from input
    def nextLine(self):
        str = ""
        try:
            str = self.br.readLine()
        except IOException as e:
            e.printStackTrace()

        return str

# Create an instance of FastReader for input
scan = FastReader()

def main():
    t = 1 # Number of test cases (currently set to 1)
    while t > 0:
        solve() # Call the solve method for processing
        t -= 1

def solve():
    # Read the number of elements in the array
    t = scan.nextInt()
    arr = [0] * t

    # Populate the array with input values
    for i in range(t):
        arr[i] = scan.nextInt()

    prevWinner = 0 # Variable to track the previous winner

    # Iterate through the array to determine the winner for each element
    for i in range(t):
        # Check if the current element is 1
        if arr[i] == 1:
            # If the previous winner is 0, set the previous winner to 2
            if prevWinner == 0:
                prevWinner = 2

        # Determine the winner based on the previous winner and the current element
        if prevWinner == 2 or prevWinner == 0:
            # If the previous winner is 2 or 0, check the parity of (arr[i] - 1)
            if (arr[i] - 1) % 2 == 0:
                print(2) # Print winner 2
                prevWinner = 2 # Update previous winner
            else:
                print(1) # Print winner 1
                prevWinner = 1 # Update previous winner
        else:
            # If the previous winner is 1, check the parity of (arr[i] - 1)
            if (arr[i] - 1) % 2 == 0:
                print(1) # Print winner 1
                prevWinner = 1 # Update previous winner
            else:
                print(2) # Print winner 2
                prevWinner = 2 # Update previous winner

main()


