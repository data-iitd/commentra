# Input the number of digits in binary representation
n = int(input())

# Initialize an empty string's' to store binary representation
s = ""

# Check if the number is zero and print '0' if it is
if n == 0:
    print('0')
    exit()

# Iterate through the number from the least significant bit to the most significant bit
i = 1
while n!= 0:
    # If the number is even, add '0' to the binary representation
    if n % 2 == 0:
        s += '0'
    else:
        # If the number is odd, add '1' to the binary representation
        s += '1'

    # Update the number by subtracting the absolute value of the remainder when the number is divided by 2 and the remainder itself
    n -= abs(n % 2)

    # Update the number by dividing it by -2 (since we subtracted the remainder in the previous step, we need to divide by -2 to get the next number)
    n /= -2

# Reverse the binary representation and print it
print(s[::-1])

