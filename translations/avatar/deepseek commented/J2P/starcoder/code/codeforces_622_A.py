import sys
import math

# Step 2: Define the Scanner and PrintWriter for input and output operations.
sc = __import__('sys').stdin
out = __import__('sys').stdout

# Step 3: Implement the solve method to find the position of a given value in a sequence.
def solve():
    position = int(sc.readline())
    nrstSeqStartIndx = 1

    # Step 4: Find the starting index of the sequence where the position might be located.
    while getValueAtIndex(nrstSeqStartIndx * 2) < position:
        nrstSeqStartIndx *= 2

    # Step 4: Find the exact position within the sequence.
    while getValueAtIndex(nrstSeqStartIndx + 1) <= position:
        nrstSeqStartIndx += 1

    startIndex = getValueAtIndex(nrstSeqStartIndx)
    out.write(str(position - startIndex) + '\n')

# Step 4: Implement the getValueAtIndex method to calculate the value at a specific index in the sequence.
def getValueAtIndex(index):
    return 1 + ((index - 1) * index / 2)

# Step 5: Implement the main method to initialize the input and call the solve method.
def main():
    # Step 7: Initialize the input reader for the in class.
    in.init(sc)
    solve()
    out.close()

# Step 7: Implement the in class to handle input operations.
class in:
    reader = None
    tokenizer = None

    @classmethod
    def init(cls, input):
        cls.reader = input
        cls.tokenizer = __import__('re').compile(' *').split

    @classmethod
    def next(cls):
        return cls.tokenizer(cls.reader.readline())

    @classmethod
    def nextInt(cls):
        return int(cls.next())

    @classmethod
    def nextDouble(cls):
        return float(cls.next())

    @classmethod
    def nextLong(cls):
        return int(cls.next())

if __name__ == '__main__':
    main()

# 