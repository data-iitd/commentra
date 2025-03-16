mod = 998244353

# Declare a static integer variable 'mod' with the value 998244353

nchoosek = [[0] * 4001 for _ in range(4001)]

# Initialize the 'nchoosek' array with dimensions 4001 x 4001 and fill it with zeros

for i in range(len(nchoosek)):
    # Iterate through each row of the 'nchoosek' array
    nchoosek[i][0] = nchoosek[i][i] = 1

# Set the first element of each row and the last element of each row to 1

for i in range(2, len(nchoosek)):
    # Iterate through each row starting from the third row
    for j in range(1, i):
        # Iterate through each column starting from the second column
        nchoosek[i][j] = (nchoosek[i - 1][j] + nchoosek[i - 1][j - 1]) % mod

# Calculate the binomial coefficients using the recursive formula

k = int(input())
# Read the first integer 'k' from the console

n = int(input())
# Read the second integer 'n' from the console

for i in range(2, 2 * k + 1):
    # Iterate through all possible values of 'i' from 2 to 2*k
    if i > k:
        pairs = k - i // 2
    else:
        pairs = (i - 1) // 2

    # Calculate the number of pairs based on the value of 'i'
    active = k - 2 * pairs

    # Declare an integer variable 'active' to store the number of active elements
    if i % 2 == 0:
        active -= 1

    # If 'i' is even, decrease the number of active elements by 1

    times2 = 1
    # Declare a long variable 'times2' to store the intermediate result for calculating 'nCj'

    total = 0
    # Declare a long variable 'total' to store the final result

    for j in range(pairs + 1):
        # Iterate through each pair 'j' from 0 to 'pairs'
        choice = times2 * nchoosek[pairs][j] % mod
        # Calculate the binomial coefficient 'nCj' using the previously calculated binomial coefficients

        times2 = times2 * 2 % mod
        # Multiply the result by 2 to get 'nCj+1'

        if active + j - 1 < 0:
            continue

        # If the number of active elements is less than 0, skip to the next iteration
        total += choice * nchoosek[n + active - 1][active + j - 1]
        # Multiply the result with the corresponding element of the 'nchoosek' array

        if i % 2 == 0:
            # If 'i' is even, add the result multiplied by the element at the position 'n+active-2, active+j-1'
            total += choice * nchoosek[n + active - 2][active + j - 1]

        # Add the result multiplied by the corresponding element of the 'nchoosek' array (if 'i' is even)

        total %= mod
        # Take the modulo to ensure the result does not exceed the value of 'mod'

    # Calculate the final result by summing up all the intermediate results
    print(total)
    # Print the final result to the console

# <END-OF-CODE>
