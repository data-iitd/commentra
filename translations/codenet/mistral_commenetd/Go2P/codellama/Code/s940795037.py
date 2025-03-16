
# Importing necessary packages
import sys

# Creating a new scanner instance
sc = Scanner()

# Reading the first integer from the standard input
n = sc.nextInt()
# Initializing the answer variable
ans = 0.0

# Iterating through the given number of integers
for i in range(n):
    # Reading the next integer from the standard input
    tmp = 1 / float(sc.nextInt())
    # Adding the reciprocal of the current integer to the answer
    ans += tmp

# Printing the final answer
print(1/ans)

# Scanner class definition
class Scanner:
    # Defining the reader instance
    r = sys.stdin
    buf = []
    p = 0

    # NewScanner function initializes a new scanner instance
    def __init__(self):
        # Creating a new buffered reader instance
        self.r = sys.stdin

    # Next function reads the next token from the standard input
    def next(self):
        # Preprocessing the input buffer
        self.pre()
        # Reading the next token from the input buffer
        start = self.p
        for i in range(self.p, len(self.buf)):
            # Checking if the current character is a whitespace character
            if self.buf[i] == ' ':
                # If yes, then setting the end position of the token
                break
        # Reading the token from the input buffer
        result = ''.join(self.buf[start:i])
        # Incrementing the position of the input buffer pointer
        self.p = i + 1
        # Returning the token
        return result

    # NextLine function reads the next line from the standard input
    def nextLine(self):
        # Preprocessing the input buffer
        self.pre()
        # Reading the next line from the input buffer
        start = self.p
        self.p = len(self.buf)
        # Reading the rest of the line if available
        self.readLine()
        # Creating a slice from the current position to the end of the input buffer
        result = ''.join(self.buf[start:])
        # Returning the line
        return result

    # NextInt function reads the next integer from the standard input
    def nextInt(self):
        # Reading the next token as a string
        token = self.next()
        # Converting the token to an integer
        v = int(token)
        # Returning the integer
        return v

    # NextIntArray function reads an array of integers from the standard input
    def nextIntArray(self):
        # Reading the next token as a string
        token = self.next()
        # Initializing an empty slice
        result = []
        # Reading each integer from the standard input and appending it to the slice
        while True:
            # Checking if the current token is an integer
            if len(token) > 0 and token[len(token) - 1] >= '0' and token[len(token) - 1] <= '9':
                # If yes, then converting the token to an integer and appending it to the slice
                v = int(token)
                result.append(v)
                # Reading the next token
                token = self.next()
                # If the current token is not a space character, then there is an error in the input
                if token[0] != ' ':
                    raise Exception("Invalid input")
            else:
                # If the current token is not an integer, then the input is invalid
                raise Exception("Invalid input")
            # Checking if the next token is the end of the input
            if token == "":
                break
        # Returning the slice
        return result

    # NextMap function reads a map from the standard input
    def nextMap(self):
        # Reading the next token as a string
        token = self.next()
        # Initializing an empty map
        mp = {}
        # Reading each key-value pair from the standard input and adding it to the map
        while True:
            # Checking if the current token is an integer
            if len(token) > 0 and token[len(token) - 1] >= '0' and token[len(token) - 1] <= '9':
                # If yes, then converting the token to an integer and adding it as a key to the map
                k = int(token)
                mp[k] = True
                # Reading the next token
                token = self.next()
                # If the current token is not a colon character, then there is an error in the input
                if token[0] != ':':
                    raise Exception("Invalid input")
                # Reading the next token as a boolean value
                v = self.next() == "true"
                # Adding the value to the map
                mp[k] = v
                # If the current token is not a space character, then there is an error in the input
                if token[0] != ' ':
                    raise Exception("Invalid input")
            else:
                # If the current token is not an integer, then the input is invalid
                raise Exception("Invalid input")
            # Checking if the next token is the end of the input
            if token == "":
                break
        # Returning the map
        return mp

    # pre function preprocesses the input buffer
    def pre(self):
        # If the position of the input buffer pointer is at the end of the buffer, then reading the next line from the standard input
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    # readLine function reads a line from the standard input and stores it in the input buffer
    def readLine(self):
        # Reading a line from the standard input
        l, p, e = self.r.readline()
        # If there is an error, then panicking
        if e != None:
            raise Exception(e)
        # Appending the line to the input buffer
        self.buf = self.buf + l
        # Setting the position of the input buffer pointer to the end of the line
        self.p = len(self.buf)

# END-OF-CODE
