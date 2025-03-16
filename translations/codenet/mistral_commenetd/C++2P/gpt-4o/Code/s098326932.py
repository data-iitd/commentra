def f(N):
    # Initialize a list to store digits of the number
    a = [0] * 20
    d = 0  # Index to store the current digit position

    # Extract digits from N and store them in the list 'a'
    while N > 0:
        a[d] = N % 10  # Store the current digit
        N //= 10  # Move to the next digit
        d += 1  # Increment the index

    # Initialize minimum ratio and the result
    m = 1e18
    res = N

    # Iterate through each digit position from 0 to the last digit position
    for i in range(d + 1):
        # Initialize sum of digits before the current digit position
        bunsi = 0
        # Initialize the sum of digits after the current digit position
        bunbo = 9 * i

        # Calculate the sum of digits before the current digit position
        for j in range(d - 1, -1, -1):
            # Update the sum of digits before the current digit position
            bunsi *= 10
            if j < i:
                bunsi += 9  # Add 9 for each digit before the current digit position
            else:
                bunsi += a[j]  # Add the current digit

            # Update the sum of digits after the current digit position
            if j >= i:
                bunbo += a[j]

        # Calculate the ratio of digits before the current digit position to the sum of digits before and after the current digit position
        frac = bunsi / bunbo

        # Update the minimum ratio and the result if the current ratio is smaller than the previous minimum ratio
        if frac < m:
            m = frac
            res = bunsi

    # Return the number with the minimum ratio of digits to total number
    return res

# Main function to read the input and print the output
if __name__ == "__main__":
    # Read the number of test cases
    K = int(input())

    # Initialize the number with the minimum ratio of digits to total number
    N = f(1)

    # Print the answer for each test case
    for _ in range(K):
        print(N)
        N = f(N + 1)

# <END-OF-CODE>
