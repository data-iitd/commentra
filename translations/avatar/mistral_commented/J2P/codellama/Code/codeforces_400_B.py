
import sys

# Reading the first two integers from the input
n, m = map(int, sys.stdin.readline().strip().split())

# Creating an array of strings to store input strings
arrs = [sys.stdin.readline().strip() for _ in range(n)]

# Initializing an integer array to store the length of substrings between "G" and "S"
length = [0] * n
index = 0
returnDex = -1

# Iterating through each string in the array and finding the length of substrings between "G" and "S"
for tmp in arrs:
    dexG = tmp.find("G")
    dexS = tmp.find("S")

    # Checking if "G" comes before "S" in the current string
    if dexG > dexS:
        returnDex = index
        break

    # Storing the length of the substring between "G" and "S" in the length array
    length[index] = dexS - dexG
    index += 1

# Creating a HashSet to store the unique lengths of substrings
set = set()

# Iterating through the length array and adding each unique length to the HashSet
for len in length:
    set.add(len)

# Checking if there is a string with "G" before "S"
if returnDex == -1:
    # Printing the result if there is no such string
    print(returnDex)
else:
    # Printing the size of the HashSet if there is a string with "G" before "S"
    print(len(set))

