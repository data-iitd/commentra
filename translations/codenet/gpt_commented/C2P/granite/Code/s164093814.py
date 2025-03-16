
# Python code to implement the same functionality as the given C code

# Define the size of the hash table and maximum length of strings
M = 1046527
L = 14

# Initialize the hash table with empty strings
H = [""] * M

# Function to convert a character to a corresponding integer value
def getChar(ch):
    if ch == "A": return 1
    elif ch == "C": return 2
    elif ch == "G": return 3
    elif ch == "T": return 4
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
def h1(key): return key % M

# Hash function h2: Computes the secondary hash index for collision resolution
def h2(key): return 1 + (key % (M - 1))

# Function to find a string in the hash table
def find(str):
    key = getKey(str)
    i = 0
    while True:
        hash = (h1(key) + i * h2(key)) % M
        if H[hash] == str: return True
        elif H[hash] == "": return False
        i += 1

# Function to insert a string into the hash table
def insert(str):
    key = getKey(str)
    i = 0
    while True:
        hash = (h1(key) + i * h2(key)) % M
        if H[hash] == str: return True
        elif H[hash] == "":
            H[hash] = str
            return False
        i += 1

# Main function to read commands and process them
def main():
    n = int(input())
    for i in range(n):
        com, str = input().split()
        if com == "insert":
            insert(str)
        else:
            if find(str):
                print("yes")
            else:
                print("no")

# Call the main function to start the program
main()

