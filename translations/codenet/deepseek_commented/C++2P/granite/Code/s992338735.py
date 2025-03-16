
# Read the number of elements (N)
while True:
    N = int(input())
    if N <= 0:
        break
    # Initialize variables for maximum, minimum, sum, and index
    M = -1
    m = 1001
    addup = 0
    for i in range(N):
        # Read each element and update the maximum, minimum, and sum
        S = int(input())
        addup += S
        if S > M:
            M = S
        if S < m:
            m = S
    # Calculate the average of the remaining numbers
    print((addup - M - m) / (N - 2))

# End the loop and main function
print("