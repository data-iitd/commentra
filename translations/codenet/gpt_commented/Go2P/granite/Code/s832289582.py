
import sys

# Initialize the input scanner with a buffer size of 256 KB
sc = inputScanner(True, 256)

# Read the integer values N and P, and the string S from input
N, P, S = sc.nextInt(), sc.nextInt(), sc.nextStr()

# Check the sub-numbers based on the conditions and print the result
answer = checkSubNumbers(N, P, S)
print(answer)

# inputScanner wraps bufio.Scanner for easier input handling
class inputScanner:
    def __init__(self, enabledScanWords, sizeInKB):
        self.scanner = bufio.Scanner(sys.stdin)
        if enabledScanWords:
            self.scanner.word_chars = bytes(string.ascii_letters + string.digits, 'utf-8') # Set the scanner to split input by words
        capacity = sizeInKB * 1024 # Calculate the buffer capacity in bytes
        buf = bytearray(capacity) # Create a buffer of the specified size
        self.scanner.buffer = buf # Set the buffer for the scanner

    def nextInt(self):
        i = int(self.nextStr()) # Convert the next string to an integer
        return i # Return the integer value

    def nextUInt64(self):
        i = int(self.nextStr()) # Convert the next string to uint64
        return i # Return the uint64 value

    def nextStr(self):
        self.scanner.scan() # Scan the next input
        return self.scanner.string() # Return the scanned text

# checkSubNumbers determines the method to check sub-numbers based on the value of P
def checkSubNumbers(N, P, S):
    if P == 2 or P == 5:
        # If P is 2 or 5, use the specific check for these primes
        return checkTwoOrFive(N, P, S)
    else:
        # For other primes, use the general check
        return checkNotTwoNorFive(N, P, S)

# checkTwoOrFive counts the sub-numbers divisible by 2 or 5
def checkTwoOrFive(N, P, S):
    answer = 0
    n = 0

    # Iterate through the string S from the end to the beginning
    for i in range(N - 1, -1, -1):
        # Convert the character to an integer
        n = int(S[i])

        # Check if the digit is divisible by P and update the answer
        if n % P == 0:
            answer += i + 1 # Count the number of valid sub-numbers

    return answer

# checkNotTwoNorFive counts the sub-numbers for primes other than 2 and 5
def checkNotTwoNorFive(N, P, S):
    multiplier = 1 # Initialize the multiplier for 10^i % P
    answer = 0 # Initialize the answer counter
    remainderLookup = [0] * P # Array to keep track of remainders
    prevRemaider = -1 # Variable to store the previous remainder
    digit = 0
    remainder = 0
    count = 0

    # Iterate through the string S from the end to the beginning
    for i in range(N - 1, -1, -1):
        digit = int(S[i]) # Convert the character to an integer

        # Calculate the current remainder based on the previous remainder
        if prevRemaider == -1: # First digit case
            remainder = digit % P
        else:
            remainder = (((multiplier * digit) % P) + prevRemaider) % P

        # If the remainder is zero, increment the answer
        if remainder == 0:
            answer += 1

        # Update the count of sub-numbers with the current remainder
        count = remainderLookup[remainder]
        answer += count # Add the count of previous occurrences of this remainder
        count += 1 # Increment the count for this remainder
        remainderLookup[remainder] = count # Store the updated count
        prevRemaider = remainder # Update the previous remainder
        multiplier = (multiplier * 10) % P # Update the multiplier for the next digit

    return answer

# 