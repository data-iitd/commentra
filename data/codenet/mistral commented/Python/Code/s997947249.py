
N, K = map(int, input().split())
# Assign the values obtained from user input to variables N and K

if N % K == 0:
# Check if the remainder of N divided by K is equal to zero
    print(0)
# If the condition is true, print the number 0
else:
# If the condition is false
    print(1)
# Print the number 1