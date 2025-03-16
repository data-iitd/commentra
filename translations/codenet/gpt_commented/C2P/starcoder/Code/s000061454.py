# <START-OF-CODE>

# Infinite loop to continuously accept input until an error occurs
while(1):
    # Read three integers a, b, and n from standard input
    # Break the loop if input fails (input returns '')
    a, b, n = input().split()
    if a == '': break

    # Adjust 'a' to be the remainder when divided by 'b'
    a = int(a) - int(a) / int(b) * int(b)
    # Initialize sum to accumulate the result
    sum = 0

    # Loop 'n' times to process each digit
    for i in range(1, int(n) + 1):
        # Scale 'a' by 10 to shift left for the next digit
        a *= 10

        # Find the largest digit 'j' (0-9) such that b*j <= a
        for j in range(9, -1, -1):
            if b * j <= a: break # If condition is met, exit the loop

        # Subtract the value of b*j from 'a'
        a -= b * j
        # Add the digit 'j' to the sum
        sum += j

    # Output the final sum for the current input set
    print(sum)

# 