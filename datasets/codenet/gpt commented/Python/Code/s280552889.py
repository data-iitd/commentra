# Read an integer input from the user
N = int(input())

# Check if the number is even
if N % 2 == 0:
    # If N is even, print half of N
    print(N // 2)
else:
    # If N is odd, print half of N plus one
    print(N // 2 + 1)
