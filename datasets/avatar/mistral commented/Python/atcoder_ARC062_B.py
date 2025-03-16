# Initialize an empty list to store input characters
s = list(input())

# Initialize counters for 'g' and 'p' symbols
num_g, num_p = 0, 0

# Initialize score variable
score = 0

# Iterate through each character in the list 's'
for x in s:

    # Check if current character is 'g'
    if x == 'g':

        # Check if number of 'g' symbols is greater than number of 'p' symbols
        if num_g - num_p > 0:

            # Increment score and number of 'p' symbols
            score += 1
            num_p += 1

            # Comment: If there are more 'g' symbols than 'p' symbols, increment score and update number of 'p' symbols

        else:

            # Do not change score and increment number of 'g' symbols
            score = score
            num_g += 1

            # Comment: If there are less or equal 'g' symbols than 'p' symbols, do not change score and update number of 'g' symbols

    # Check if current character is 'p'
    elif x == 'p':

        # Check if number of 'g' symbols is greater than number of 'p' symbols
        if num_g - num_p > 0:

            # Do not change score and increment number of 'p' symbols
            score = score
            num_p += 1

            # Comment: If there are more 'g' symbols than 'p' symbols, do not change score and update number of 'p' symbols

        else:

            # Decrement score and increment number of 'g' symbols
            score -= 1
            num_g += 1

            # Comment: If there are less or equal 'g' symbols than 'p' symbols, decrement score and update number of 'g' symbols

# Print the final score
print(score)

# Comment: After iterating through all characters in the list 's', print the final score
