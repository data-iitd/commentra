# Declare variables A and B to store input values
A, B = map(int, input().split())

# Initialize answer variable ans to 0
ans = 0

# Initialize counter variable out to 1
out = 1

# Use a while loop to find the number of times A can be added to get a value greater than or equal to B
while out < B:
    out -= 1  # Decrement out by 1
    out += A  # Increment out by A
    ans += 1  # Increment ans by 1 each time the loop runs

# Display the answer
print("The answer is:", ans)

# End of code
# <END-OF-CODE>
