import sys
input = sys.stdin.readline

# Read input and split into two strings, a and b
a, b = input().rstrip('\n').split()

# Determine the maximum length of the two strings
x = max(len(a), len(b))

# Pad the shorter string with zeros on the left
a = a.rjust(x, '0')

# Pad the shorter string with zeros on the right
b = b.ljust(x, '0')

# Initialize an empty string to store the result
s = ''

# Initialize carry to 0
c = 0

# Loop through each digit from right to left
for i in range(x):
    # Add the corresponding digits from a and b along with the carry
    d = int(b[i]) + int(a[x - i - 1]) + c
    
    # If the sum is greater than 9, set carry to 1 and append the tens digit
    if d > 9:
        s += str(d)[1]
        c = 1
    else:
        # Otherwise, append the sum and set carry to 0
        s += str(d)
        c = 0

# If there's a carry left after the final addition, append '1'
if c == 1:
    s += '1'

# Reverse the result string and print it as an integer
print(int(s[::-1]))
