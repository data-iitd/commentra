
n = int(input("Enter an integer: "))  # Read an integer from the user

while n % 2 == 0:  # While n is even
    n //= 2  # Divide n by 2 to remove the last even factor

if n == 1:  # If n is now 1
    print("YES")  # Print 'YES'
else:  # Otherwise
    print("NO")  # Print 'NO'