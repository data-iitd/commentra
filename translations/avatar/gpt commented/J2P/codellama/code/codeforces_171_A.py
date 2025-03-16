
# FastReader class to handle fast input
class FastReader:
    def __init__(self):
        self.br = open(0)

    def next(self):
        while True:
            # Check if there are no more tokens available
            if self.st == None or not self.st.hasMoreElements():
                try:
                    # Read a new line and tokenize it
                    self.st = StringTokenizer(self.br.readline())
                except:
                    return ""
            # Return the next token
            return self.st.nextToken()

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return long(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        str = ""
        try:
            str = self.br.readline()
        except:
            pass
        return str

# Main function
def main():
    # Create an instance of FastReader for input
    sc = FastReader()

    # Read two integers n and m from input
    n = sc.nextInt()
    m = sc.nextInt()

    # Reverse the integer m and store the result in t
    t = reverse(m)

    # Print the sum of t and n
    print(t + n)

# Method to reverse the digits of an integer n
def reverse(n):
    # If n is a single digit, return n multiplied by 10
    if n < 10:
        return n * 10

    t = n
    r = 0

    # Loop to reverse the digits of n
    while t > 0:
        r = (r * 10) + t % 10 # Add the last digit of t to r
        t = t / 10 # Remove the last digit from t

    # Return the reversed integer
    return r

# Main function
if __name__ == "__main__":
    main()

# END-OF-CODE
