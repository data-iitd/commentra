# Read an integer input from the user
N = int(input())

# Initialize a counter variable to check divisors from 1 to 9
cnt = 1

# Loop through possible divisors from 1 to 9
while cnt <= 9:
    # Check if 'cnt' is a divisor of 'N' and if the quotient is between 1 and 9
    if N % cnt == 0 and 1 <= N / cnt <= 9:
        # If both conditions are met, print 'Yes' and exit the loop
        print('Yes')
        break
    else:
        # Increment the counter to check the next number
        cnt += 1
else:
    # If no valid divisor was found, print 'No'
    print('No')
