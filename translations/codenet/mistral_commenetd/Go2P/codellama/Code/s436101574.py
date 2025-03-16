
# Initializing scanner and writer
sc, wr = input, print

# Function to read a single string
def scanString():
    return sc().strip()

# Function to read a single rune
def scanRunes():
    return list(scanString())

# Function to read a single integer
def scanInt():
    return int(scanString())

# Function to read a single integer64
def scanInt64():
    return int(scanString())

# Function to read a single float64
def scanFloat64():
    return float(scanString())

# Function to read multiple integers
def scanInts(n):
    return [scanInt() for _ in range(n)]

# Function to print debug information
def debug(*a):
    print(*a)

# Function to get absolute value of an integer
def abs(a):
    if a < 0:
        return -a
    return a

# Function to get minimum of two integers
def min(a, b):
    if a < b:
        return a
    return b

# Function to get maximum of two integers
def max(a, b):
    if a > b:
        return a
    return b

# Main function
def main():
    # Reading input strings s and t
    s = scanRunes()
    t = scanRunes()

    # Initializing an empty slice to store answers
    ans = []

    # Iterating through all possible substrings of s that have the same length as t
    for i in range(len(s) - len(t) + 1):
        # Initializing a slice to store the modified string s
        ss = list(s)

        # Checking if the current substring matches the pattern t
        f = True
        for j in range(len(t)):
            # If the current character of s does not match the current character of t or is not '?'
            if ss[i + j] != t[j] and ss[i + j] != '?':
                # Setting flag to false and breaking the loop
                f = False
                break
            else:
                # Replacing the current character of s with the corresponding character of t
                ss[i + j] = t[j]

        # If the current substring matches the pattern t
        if f:
            # Appending the modified string to the answer slice
            ans.append(''.join(ss).replace('?', 'a'))

    # Sorting the answer slice in ascending order
    ans.sort()
    # Checking if the answer slice is empty
    if len(ans) == 0:
        # Printing "UNRESTORABLE" if the answer slice is empty
        print("UNRESTORABLE")
    else:
        # Printing the first element of the answer slice
        print(ans[0])



