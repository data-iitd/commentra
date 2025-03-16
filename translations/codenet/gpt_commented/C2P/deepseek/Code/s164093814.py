M = 1046527
L = 14

# Hash Table to store strings
H = [""] * M

# Function to convert a character to a corresponding integer value
def getChar(ch):
    if ch == 'A':
        return 1
    elif ch == 'C':
        return 2
    elif ch == 'G':
        return 3
    elif ch == 'T':
        return 4
    return 0

# Convert a string into a unique integer key using a polynomial rolling hash
def getKey(str):
    sum = 0
    p = 1
    for ch in str:
        sum += p * getChar(ch)
        p *= 5
    return sum

# Hash function h1: Computes the primary hash index
def h1(key):
    return key % M

# Hash function h2: Computes the secondary hash index for collision resolution
def h2(key):
    return 1 + (key % (M - 1))

# Function to find a string in the hash table
def find(str):
    key = getKey(str)
    i = 0
    while True:
        hash = (h1(key) + i * h2(key)) % M
        if H[hash] == str:
            return True
        elif H[hash] == "":
            return False
        i += 1
    return False

# Function to insert a string into the hash table
def insert(str):
    key = getKey(str)
    i = 0
    while True:
        hash = (h1(key) + i * h2(key)) % M
        if H[hash] == str:
            return True
        elif H[hash] == "":
            H[hash] = str
            return False
        i += 1
    return False

# Main function to process commands
def main():
    n = int(input())
    for _ in range(n):
        com, str = input().split()
        if com[0] == 'i':
            insert(str)
        else:
            if find(str):
                print("yes")
            else:
                print("no")

main()
