# Declare variables A and B to store input values
A = int(input())
B = int(input())

# Initialize answer variable ans to 0
ans = 0

# Initialize counter variable out to 1
out = 1

# Use a while loop to find the number of times A can be added to get a value greater than or equal to B
while out < B:
    out -= 1
    out += A
    ans += 1

# Display the answer
print("The answer is: " + str(ans))

# Return 0 to indicate successful execution
return 0

