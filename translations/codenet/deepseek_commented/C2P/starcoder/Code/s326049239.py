# <START-OF-CODE>

# Read input from stdin
a = int(input())

# Start a while loop to read input
while a!= 0:
    # Initialize counters 'c' and 'k' to 0
    c = 0
    k = 0

    # Check if 'a' is less than 3
    if a < 3:
        # Print 0 if 'a' is less than 3
        print(0)
    else:
        # Store the initial value of 'a' in 'b' for later use
        b = a

        # Decrement 'a' until it becomes 0
        while a > 0:
            # Decrement 'b' in each iteration
            b -= 1

            # Increment 'c' in each iteration
            c += 1

            # Check if 'c' equals 3
            if c == 3:
                # Increment 'k'
                k += 1

                # Reset 'c' to 0
                c = 0

        # Print the number of times 'c' reset to 0
        print(k)

    # Read input from stdin
    a = int(input())

# 