mod = 998244353
nchoosek = [[0] * 4001 for _ in range(4001)]

# Initialize the nchoosek array for binomial coefficients
for i in range(len(nchoosek)):
    nchoosek[i][0] = nchoosek[i][i] = 1  # nchoosek[i][0] and nchoosek[i][i] are 1

# Fill the nchoosek array using dynamic programming
for i in range(2, len(nchoosek)):
    for j in range(1, i):
        nchoosek[i][j] = (nchoosek[i - 1][j] + nchoosek[i - 1][j - 1]) % mod

# Read input values k and n
k, n = map(int, input().split())

# Main loop to compute and print results for each i from 2 to 2*k
for i in range(2, 2 * k + 1):
    if i > k:
        pairs = k - i // 2  # Calculate pairs based on i
    else:
        pairs = (i - 1) // 2  # Calculate pairs based on i
    active = k - 2 * pairs  # Calculate active elements
    if i % 2 == 0:
        active -= 1  # Adjust active if i is even

    times2 = 1  # Initialize times2 for calculating powers of 2
    total = 0  # Initialize total for storing the result

    # Calculate total using binomial coefficients
    for j in range(pairs + 1):
        choice = times2 * nchoosek[pairs][j] % mod  # Calculate choice
        times2 = times2 * 2 % mod  # Update times2
        if active + j - 1 < 0:
            continue  # Skip if invalid
        total += choice * nchoosek[n + active - 1][active + j - 1]  # Add to total
        if i % 2 == 0:
            total += choice * nchoosek[n + active - 2][active + j - 1]  # Add for even i
        total %= mod  # Ensure total is within the modulo

    print(total)  # Print the result
# <END-OF-CODE>
