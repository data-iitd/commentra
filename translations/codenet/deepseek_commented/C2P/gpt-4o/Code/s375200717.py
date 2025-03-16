# Read an integer n from the standard input
n = int(input())

# Iterate from 1 to n (inclusive)
for i in range(1, n + 1):
    a = i
    
    # Check if the current number i is divisible by 3
    if a % 3 == 0:
        print(i, end=' ')
    else:
        # Check each digit of i to see if it contains the digit 3
        while a:
            if a % 10 == 3:
                print(i, end=' ')
                break
            a //= 10

# Print a newline character
print()

# <END-OF-CODE>
