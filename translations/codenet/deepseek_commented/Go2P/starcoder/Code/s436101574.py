import sys

# Reads a single string from the input.
def scanString():
    return sys.stdin.readline().strip()

# Reads a list of integers from the input.
def scanInts():
    return [int(x) for x in sys.stdin.readline().strip().split()]

# Reads a list of runes from the input.
def scanRunes():
    return list(scanString())

# Returns the absolute value of an integer.
def abs(a):
    return a if a >= 0 else -a

# Returns the smaller of two integers.
def min(a, b):
    return a if a < b else b

# Returns the larger of two integers.
def max(a, b):
    return a if a > b else b

# Main function where the program execution begins.
def main():
    s = scanRunes()
    t = scanRunes()

    ans = []
    for i in range(len(s)-len(t)+1):
        f = True
        ss = list(s)
        for j in range(len(t)):
            if s[i+j]!= t[j] and s[i+j]!= '?':
                f = False
                break
            else:
                ss[i+j] = t[j]
        if f:
            ans.append(''.join(ss))

    if len(ans) == 0:
        print("UNRESTORABLE")
    else:
        print(min(ans))

# 