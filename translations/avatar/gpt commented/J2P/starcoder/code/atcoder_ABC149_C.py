# Importing the math module for mathematical operations
import math

# Create a function to check if a number is prime
def isPrime(x):
    # Check if x is equal to 2
    if x == 2:
        return True
    # Check if x is even
    if x % 2 == 0:
        return False
    # Check for factors of x from 3 to the square root of x, incrementing by 2 (to check only odd numbers)
    for i in range(3, int(math.sqrt(x)) + 1, 2):
        # If i divides x, then x is not prime
        if x % i == 0:
            return False
    # If no divisors were found, i will be greater than sqrtNum, indicating x is prime
    return True

# Create a function to find the next prime number
def nextPrime(x):
    # If x is even and not equal to 2, increment x to make it odd
    if x!= 2 and x % 2 == 0:
        x += 1
    # Infinite loop to find the next prime number
    while True:
        # If x is prime, return it
        if isPrime(x):
            return x
        # Increment x by 2 to check the next odd number
        x += 2

# Create a function to read an integer input from the user
def readInt():
    # Create a variable to hold the user's input
    x = input("Enter an integer: ")
    # Return the user's input as an integer
    return int(x)

# Create a function to read a float input from the user
def readFloat():
    # Create a variable to hold the user's input
    x = input("Enter a float: ")
    # Return the user's input as a float
    return float(x)

# Create a function to read a string input from the user
def readString():
    # Create a variable to hold the user's input
    x = input("Enter a string: ")
    # Return the user's input as a string
    return str(x)

# Create a function to read a boolean input from the user
def readBoolean():
    # Create a variable to hold the user's input
    x = input("Enter a boolean: ")
    # Return the user's input as a boolean
    return bool(x)

# Create a function to read a list input from the user
def readList():
    # Create a variable to hold the user's input
    x = input("Enter a list: ")
    # Return the user's input as a list
    return list(x)

# Create a function to read a tuple input from the user
def readTuple():
    # Create a variable to hold the user's input
    x = input("Enter a tuple: ")
    # Return the user's input as a tuple
    return tuple(x)

# Create a function to read a dictionary input from the user
def readDict():
    # Create a variable to hold the user's input
    x = input("Enter a dictionary: ")
    # Return the user's input as a dictionary
    return dict(x)

# Create a function to read a set input from the user
def readSet():
    # Create a variable to hold the user's input
    x = input("Enter a set: ")
    # Return the user's input as a set
    return set(x)

# Create a function to read a frozenset input from the user
def readFrozenset():
    # Create a variable to hold the user's input
    x = input("Enter a frozenset: ")
    # Return the user's input as a frozenset
    return frozenset(x)

# Create a function to read a complex input from the user
def readComplex():
    # Create a variable to hold the user's input
    x = input("Enter a complex: ")
    # Return the user's input as a complex
    return complex(x)

# Create a function to read a byte input from the user
def readByte():
    # Create a variable to hold the user's input
    x = input("Enter a byte: ")
    # Return the user's input as a byte
    return bytes(x, "utf-8")

# Create a function to read a bytearray input from the user
def readBytearray():
    # Create a variable to hold the user's input
    x = input("Enter a bytearray: ")
    # Return the user's input as a bytearray
    return bytearray(x, "utf-8")

# Create a function to read a memoryview input from the user
def readMemoryview():
    # Create a variable to hold the user's input
    x = input("Enter a memoryview: ")
    # Return the user's input as a memoryview
    return memoryview(x)

# Create a function to read a range input from the user
def readRange():
    # Create a variable to hold the user's input
    x = input("Enter a range: ")
    # Return the user's input as a range
    return range(x)

# Create a function to read a slice input from the user
def readSlice():
    # Create a variable to hold the user's input
    x = input("Enter a slice: ")
    # Return the user's input as a slice
    return slice(x)

# Create a function to read a str input from the user
def readStr():
    # Create a variable to hold the user's input
    x = input("Enter a str: ")
    # Return the user's input as a str
    return str(x)

# Create a function to read a tuple input from the user
def readTuple():
    # Create a variable to hold the user's input
    x = input("Enter a tuple: ")
    # Return the user's input as a tuple
    return tuple(x)

# Create a function to read a type input from the user
def readType():
    # Create a variable to hold the user's input
    x = input("Enter a type: ")
    # Return the user's input as a type
    return type(x)

# Create a function to read a zip input from the user
def readZip():
    # Create a variable to hold the user's input
    x = input("Enter a zip: ")
    # Return the user's input as a zip
    return zip(x)

# Create a function to read a map input from the user
def readMap():
    # Create a variable to hold the user's input
    x = input("Enter a map: ")
    # Return the user's input as a map
    return map(x)

# Create a function to read a filter input from the user
def readFilter():
    # Create a variable to hold the user's input
    x = input("Enter a filter: ")
    # Return the user's input as a filter
    return filter(x)

# Create a function to read a reversed input from the user
def readReversed():
    # Create a variable to hold the user's input
    x = input("Enter a reversed: ")
    # Return the user's input as a reversed
    return reversed(x)

# Create a function to read a enumerate input from the user
def readEnumerate():
    # Create a variable to hold the user's input
    x = input("Enter a enumerate: ")
    # Return the user's input as a enumerate
    return enumerate(x)

# Create a function to read a sorted input from the user
def readSorted():
    # Create a variable to hold the user's input
    x = input("Enter a sorted: ")
    # Return the user's input as a sorted
    return sorted(x)

# Create a function to read a sum input from the user
def readSum():
    # Create a variable to hold the user's input
    x = input("Enter a sum: ")
    # Return the user's input as a sum
    return sum(x)

# Create a function to read a abs input from the user
def readAbs():
    # Create a variable to hold the user's input
    x = input("Enter a abs: ")
    # Return the user's input as a abs
    return abs(x)

# Create a function to read a all input from the user
def readAll():
    # Create a variable to hold the user's input
    x = input("Enter a all: ")
    # Return the user's input as a all
    return all(x)

# Create a function to read a any input from the user
def readAny():
    # Create a variable to hold the user's input
    x = input("Enter a any: ")
    # Return the user's input as a any
    return any(x)

# Create a function to read a ascii input from the user
def readAscii():
    # Create a variable to hold the user's input
    x = input("Enter a ascii: ")
    # Return the user's input as a ascii
    return ascii(x)

# Create a function to read a bin input from the user
def readBin():
    # Create a variable to hold the user's input
    x = input("Enter a bin: ")
    # Return the user's input as a bin
    return bin(x)

# Create a function to read a bool input from the user
def readBool():
    # Create a variable to hold the user's input
    x = input("Enter a bool: ")
    # Return the user's input as a bool
    return bool(x)

# Create a function to read a bytearray input from the user
def readBytearray():
    # Create a variable to hold the user's input
    x = input("Enter a bytearray: ")
    # Return the user's input as a bytearray
    return bytearray(x)

# Create a function to read a bytes input from the user
def readBytes():
    # Create a variable to hold the user's input
    x = input("Enter a bytes: ")
    # Return the user's input as a bytes
    return bytes(x)

# Create a function to read a callable input from the user
def readCallable():
    # Create a variable to hold the user's input
    x = input("Enter a callable: ")
    # Return the user's input as a callable
    return callable(x)

# Create a function to read a chr input from the user
def readChr():
    # Create a variable to hold the user's input
    x = input("Enter a chr: ")
    # Return the user's input as a chr
    return chr(x)

# Create a function to read a classmethod input from the user
def readClassmethod():
    # Create a variable to hold the user's input
    x = input("Enter a classmethod: ")
    # Return the user's input as a classmethod
    return classmethod(x)

# Create a function to read a compile input from the user
def readCompile():
    # Create a variable to hold the user's input
    x = input("Enter a compile: ")
    # Return the user's input as a compile
    return compile(x)

# Create a function to read a complex input from the user
def readComplex():
    # Create a variable to hold the user's input
    x = input("Enter a complex: ")
    # Return the user's input as a complex
    return complex(x)

# Create a function to read a delattr input from the user
def readDelattr():
    # Create a variable to hold the user's input
    x = input("Enter a delattr: ")
    # Return the user's input as a delattr
    return delattr(x)

# Create a function to read a dict input from the user
def readDict():
    # Create a variable to hold the user's input
    x = input("Enter a dict: ")
    # Return the user's input as a dict
    return dict(x)

# Create a function to read a dir input from the user
def readDir():
    # Create a variable to hold the user's input
    x = input("Enter a dir: ")
    # Return the use