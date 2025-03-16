
# Importing required Python packages for input and output
import sys
import string

# Class declaration and initialization of static variables
N = 200 + 10
f = [ 0 ] * N
b = [ 0 ] * N

# Function declaration and initialization of variables
def getFail(b, m):
    # Main logic of the function
    j = 0
    f[0] = f[1] = 0
    for i in range(2, m + 1):
        while j > 0 and b[j + 1]!= b[i]:
            j = f[j]
        if b[j + 1] == b[i]:
            j += 1
        f[i] = j

# Main function declaration and initialization of variables
n = int(sys.stdin.readline( ))
s1 = sys.stdin.readline( ).strip( )
str = sys.stdin.readline( ).strip( )

cnt = 0

# Concatenating the two strings and creating character arrays for each
for i in range(0, n):
    b[cnt + 1] = str[i]
    cnt += 1
for i in range(0, n):
    b[cnt + 1] = s1[i]
    cnt += 1

getFail(b, cnt)

len = min(f[cnt], min(n, n))

# Writing the output to the console
print(2 * n - len)

# Flushing the output buffer
sys.stdout.flush( )

