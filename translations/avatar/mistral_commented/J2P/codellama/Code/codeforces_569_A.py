
import sys

# Read the first integer `T` from the input
T = int(sys.stdin.readline().strip())

# Read the second integer `S` from the input
S = int(sys.stdin.readline().strip())

# Read the third integer `q` from the input
q = int(sys.stdin.readline().strip())

# Initialize the variable `previous` with the value of `S`
previous = S

# Initialize the variable `answer` with the value of 0
answer = 0

# Start a while loop that continues as long as `previous` is less than `T`
while previous < T:
    # Increment the value of `answer` by 1
    answer += 1

    # Multiply the value of `previous` by `q`
    previous *= q

# Print the value of `answer` to the standard output stream
print(answer)

