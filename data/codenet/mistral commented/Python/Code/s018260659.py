# Take an integer input from the user and assign it to the variable N
N = int(input())

# Initialize a counter variable cnt to 1
cnt = 1

# Start a while loop that continues as long as the counter is less than or equal to 9
while cnt <= 9:

    # Check if N is divisible by the counter
    if N % cnt == 0:

        # Check if the quotient of N by the counter is also an integer between 1 and 9
        if 1 <= N // cnt <= 9:

            # If both conditions are true, print 'Yes' and break out of the loop
            print('Yes')
            break

    # If the conditions are not true, increment the counter by 1 and continue the loop
    cnt += 1

# If the loop completes without finding a suitable divisor, print 'No'
else:
    print('No')
