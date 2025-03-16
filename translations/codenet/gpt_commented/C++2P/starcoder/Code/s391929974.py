# <START-OF-CODE>

# Variable to store the input number
n = 0

# Arrays to store squares and frequency counts
sq = [0] * 10000
fr = [0] * 5000

# Vector to store unique square values
com = []

# Temporary variable for calculations
tmp = 0

# Infinite loop to continuously read input until a zero is entered
while True:
    n = int(raw_input()) # Read an integer from input
    if n == 0: break # Exit the loop if the input is zero

    # Calculate the squares of numbers from 1 to n-1 modulo n
    for i in range(1, n):
        sq[i] = (i*i) % n

    com = [] # Clear the vector for storing unique squares

    # Collect unique square values into the vector 'com'
    for i in range(1, n):
        f = True # Flag to check if the square is unique
        for j in range(len(com)):
            if com[j] == sq[i]: # Check if the square is already in 'com'
                f = False # Not unique
                break
        if f: com.append(sq[i]) # Add to 'com' if unique

    # Initialize frequency array to count occurrences of differences
    for i in range(0, (n-1)/2):
        fr[i] = 0

    # Calculate the frequency of differences between unique squares
    for i in range(0, len(com)):
        for j in range(0, len(com)):
            if i!= j: # Ensure we are not comparing the same element
                tmp = com[i] - com[j] # Calculate the difference
                if tmp < 0: tmp += n # Adjust if negative
                if tmp > (n-1)/2: tmp = n - tmp # Adjust to be within the range
                fr[tmp] += 1 # Increment the frequency count for this difference

    # Output the frequency counts for differences from 1 to (n-1)/2
    for i in range(1, (n-1)/2):
        print fr[i]

# 