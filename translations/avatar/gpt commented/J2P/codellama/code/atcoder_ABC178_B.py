
# FastReader class to handle fast input
class FastReader:
    br = None
    st = None

    # Constructor to initialize BufferedReader
    def __init__(self):
        self.br = open(0)

    # Method to read the next token from input
    def next(self):
        # Check if there are no tokens left to read
        while self.st == None or not self.st.hasMoreElements():
            try:
                # Read a new line and tokenize it
                self.st = str.split(self.br.readline())
            except:
                pass
        return self.st.next()

    # Method to read the next integer from input
    def nextInt(self):
        return int(self.next())

    # Method to read the next long from input
    def nextLong(self):
        return long(self.next())

    # Method to read the next double from input
    def nextDouble(self):
        return float(self.next())

    # Method to read the next line from input
    def nextLine(self):
        str = ""
        try:
            str = self.br.readline()
        except:
            pass
        return str

# Method to compute (x^y) % mod using modular exponentiation
def modPower(x, y, mod):
    res = 1
    x %= mod # Reduce x modulo mod
    if x == 0: return 0 # If x is 0, return 0

    # Loop until y becomes 0
    while y > 0:
        # If y is odd, multiply x with result
        if y % 2 == 1:
            res = (res * x) % mod
        y = y >> 1 # Divide y by 2
        x = (x * x) % mod # Square x
    return res # Return the final result

# Pair class to hold two related values
class pair:
    first = None
    second = None

    # Constructor to initialize the pair
    def __init__(self, first, second):
        self.first = first
        self.second = second

# Main method to execute the program
def main():
    in = FastReader() # Create an instance of FastReader
    a = [0] * 4 # Array to hold four long integers

    # Read four long integers from input
    for i in range(4):
        a[i] = in.nextLong()

    # Calculate and print the maximum product of pairs from the array
    print max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2])))

if __name__ == "__main__":
    main()

