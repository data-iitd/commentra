# Read an integer N from the user
N = int(input())

# Initialize a counter variable cnt to 1
cnt = 1

# Enter a while loop that continues as long as cnt is less than or equal to 9
while cnt <= 9:
    # Check if N is divisible by cnt and if the result of the division is between 1 and 9 (inclusive)
    if N % cnt == 0 and 1 <= N / cnt <= 9:
        # If the condition is met, print 'Yes' and break out of the loop
        print('Yes')
        break
    else:
        # If the condition is not met, increment cnt by 1 and continue the loop
        cnt += 1
else:
    # If the loop completes without finding a suitable cnt, print 'No'
    print('No')
