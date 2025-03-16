A, B = map(int, input().split())  # Read two integers A and B from the standard input
ans = 0
out = 1  # Initialize out to 1

while out < B:  # Continue the loop as long as out is less than B
    out -= 1  # Decrement out by 1
    out += A  # Increment out by A
    ans += 1  # Increment ans by 1

print(ans)  # Print the value of ans to the standard output
# <END-OF-CODE>
