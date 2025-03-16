# We use the input function to read user input and store it in variables a and b
a, b = map(int, input().split())

# We check if the sum of a and b is even
if (a + b) % 2 == 0:
    # If the sum is even, we print the result by dividing it by 2
    print((a + b) // 2)
else:
    # If the sum is odd, we print "IMPOSSIBLE"
    print("IMPOSSIBLE")

# <END-OF-CODE>
