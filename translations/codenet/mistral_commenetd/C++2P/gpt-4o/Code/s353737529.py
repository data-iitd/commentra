# Function to find the greatest common divisor of two numbers
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

#-----------------------Main function-----------------------
if __name__ == "__main__":
    # Input the number of digits in binary representation
    n = int(input())

    # Initialize an empty string 's' to store binary representation
    s = ""

    # Check if the number is zero and print '0' if it is
    if n == 0:
        print('0')
    else:
        # Iterate through the number from the least significant bit to the most significant bit
        while n != 0:
            # If the number is even, add '0' to the binary representation
            if n % 2 == 0:
                s += '0'
            else:
                # If the number is odd, add '1' to the binary representation
                s += '1'

            # Update the number by subtracting the absolute value of the remainder when the number is divided by 2 and the remainder itself
            n -= abs(n % 2)

            # Update the number by dividing it by -2
            n //= -2

        # Reverse the binary representation and print it
        s = s[::-1]
        print(s)

# <END-OF-CODE>
