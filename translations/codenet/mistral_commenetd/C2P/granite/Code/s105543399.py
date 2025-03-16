
# We import the standard input/output library
import sys

# We read the first number 'n' from the standard input
n = int(sys.stdin.readline())

# We initialize the variable 'c' to zero
c = 0

# We initialize'm' to a very large negative number
m = 100000000

# We initialize 'M' to a very large positive number
M = -100000000

for i in range(1, n+1): # We start a for loop that iterates 'n' times
  # We read the current number 'a' from the standard input
  a = int(sys.stdin.readline())

  # If the current number 'a' is greater than the current maximum number 'M', we update 'M' with 'a'
  if a > M:
    M = a

  # If the current number 'a' is smaller than the current minimum number'm', we update'm' with 'a'
  if a < m:
    m = a

  # We add the current number 'a' to the variable 'c'
  c = c + a

# We print the minimum number'm', the maximum number 'M', and the sum 'c' to the standard output
print(m, M, c)

