
# Package main is the entry point of the program
def main():
    sc = newInputScanner(True, 256) # We create an instance of inputScanner with scanWords enabled and a buffer size of 256 KB
    N, P, S = sc.nextInt(), sc.nextInt(), sc.nextStr() # We read N, P, and S from the standard input using inputScanner
    answer = checkSubNumbers(N, P, S) # We call checkSubNumbers function with N, P, and S as arguments and store the result in answer variable
    print(answer) # We print the answer using print

# checkSubNumbers function checks if any subnumber of given string S is divisible by prime number P
def checkSubNumbers(N, P, S):
    answer = 0 # We initialize answer variable as 0
    var n # We define an integer variable n
    # We iterate through the string S from the last character to the first character
    for i in range(N-1, -1, -1):
        # We convert the substring from i to i+1 to an integer n
        n = int(S[i:i+1])
        # If n is divisible by P, we add its index to the answer variable
        if n%P == 0:
            answer += i + 1
    return answer

# checkNotTwoNorFive function checks if any subnumber of given string S is divisible by prime number P which is not equal to 2 or 5
def checkNotTwoNorFive(N, P, S):
    multiplier = 1 # We initialize multiplier variable as 1
    answer = 0     # We initialize answer variable as 0
    # We create a slice of length P for storing the count of remainders
    remainderLookup = [0] * P
    prevRemaider = -1 # We initialize prevRemaider variable as -1
    # We iterate through the string S from the last character to the first character
    for i in range(N-1, -1, -1):
        # We get the digit from the string S at the current index i
        digit = int(S[i])
        # If prevRemaider is equal to -1, we get the remainder of the first digit by dividing it by P
        if prevRemaider == -1:
            remainder = digit % P
        else:
            # Otherwise, we get the remainder of the current digit multiplied by multiplier and added to the previous remainder, then we get the remainder of the result by dividing it by P
            remainder = (((multiplier * digit) % P) + prevRemaider) % P
        # If the remainder is equal to 0, we add 1 to the answer variable
        if remainder == 0:
            answer += 1
        # We get the count of the current remainder from the slice remainderLookup
        count = remainderLookup[remainder]
        # We add the count to the answer variable
        answer += count
        # We update the slice remainderLookup with the new count of the current remainder
        count += 1
        remainderLookup[remainder] = count
        # We update the multiplier variable as multiplier * 10 % P
        prevRemaider = remainder
        multiplier = (multiplier * 10) % P
    return answer

# inputScanner type is a custom struct for reading input
class inputScanner:
    # We create a constructor function for inputScanner
    def __init__(self, enabledScanWords, sizeInKB):
        scanner = bufio.Scanner(sys.stdin) # We create a new bufio.Scanner instance for reading input
        if enabledScanWords:
            scanner.split(bufio.ScanWords) # We enable scanWords if it's true
        capacity = sizeInKB * 1024 # We calculate the buffer size based on the given sizeInKB
        buf = bytearray(capacity) # We create a new bytearray with the calculated buffer size
        scanner.buffer(buf, capacity) # We set the buffer for the scanner instance
        self.scanner = scanner # We set the scanner instance as the field of the inputScanner instance

    # nextInt function reads an integer from the input and converts it to an integer
    def nextInt(self):
        i = int(self.nextStr()) # We try to convert the next string to an integer
        return i # If the conversion is successful, we return the integer

    # nextUInt64 function reads an unsigned integer from the input and converts it to an unsigned integer
    def nextUInt64(self):
        i = int(self.nextStr()) # We try to convert the next string to an unsigned integer
        return i # If the conversion is successful, we return the unsigned integer

    # nextStr function reads the next string from the input
    def nextStr(self):
        self.scanner.scan() # We scan the next token from the input
        return self.scanner.text() # We return the scanned string


