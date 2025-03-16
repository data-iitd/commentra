# Take three integers as input from the user and store them in variables t, s, and q respectively
t, s, q = map(int, input().split())

# Initialize an answer counter variable ans to 0
ans = 0

# Loop while the value of s is less than t
while s < t:
    # Multiply the value of s by q and update the value of s
    s *= q
    
    # Increment the answer counter variable ans by 1
    ans += 1

# Print the final answer
print(ans)