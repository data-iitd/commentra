
# Take input from the user, split it into individual integers, and sort them
candy = sorted(map(int, input().split()))

# Check if the sum of the first two integers is equal to the third integer
print("Yes" if candy[0] + candy[1] == candy[2] else "No")


