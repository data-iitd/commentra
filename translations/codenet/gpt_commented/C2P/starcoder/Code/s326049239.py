
# <START-OF-CODE>

# Read an integer from standard input
a = int(input())

# Initialize count of individual items
c = 0

# Initialize count of groups of three
k = 0

# Check if the input number is less than 3
if a < 3:
    print("0")
else:
    # Store the original value of a in b for later use
    b = a

    # Loop to count down from a to 0
    while a:
        b -= 1
        c += 1

        # Check if we have counted three items
        if c == 3:
            k += 1
            c = 0

    # Print the total number of groups of three formed
    print(k)

# 