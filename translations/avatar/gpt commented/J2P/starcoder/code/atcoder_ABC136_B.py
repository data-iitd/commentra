
# <START-OF-CODE>

# Create a Scanner object to read input from the user
stdIn = input()

# Read an integer N from user input
N = int(stdIn)

# Initialize count to track the number of digits in N
count = 0

# Temporary variable to manipulate the value of N
temp = N

# Variable to store the final answer
ans = 0

# Count the number of digits in N
while temp > 0:
    temp = temp // 10 # Remove the last digit from temp
    count += 1 # Increment the digit count

# Loop through each digit position from 1 to count
for i in range(1, count + 1):
    # Check if we are at the last digit position
    if i == count:
        # If the last digit position is odd, calculate the contribution to ans
        if i % 2 == 1:
            ans += (N - pow(10, i - 1) + 1)
    else:
        # Handle contributions for positions other than the last
        if i == 1:
            # For the first digit position, there are 9 possibilities (1-9)
            ans += 9
        elif i % 2 == 1:
            # For odd digit positions, calculate the range of numbers
            ans += (pow(10, i) - pow(10, i - 1))

# Output the final answer
print(ans)

# 