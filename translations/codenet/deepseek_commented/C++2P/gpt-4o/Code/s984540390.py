# Define constants and variables
ans = 0
cnt = 1

# Input the value of h
h = int(input())

# Loop to calculate the answer
while h != 1:
    if h % 2 != 0:
        h -= 1  # Decrement h if it is odd
    h //= 2  # Divide h by 2
    cnt *= 2  # Double the count
    ans += cnt  # Increment the sum by the current count

# Output the final result
print(ans + 1)

# <END-OF-CODE>
