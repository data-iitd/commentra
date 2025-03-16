MAX_N = 1000

# Read inputs m, nmi, and nma until nmi is not equal to 0
while True:
    m, nmi, nma = map(int, input().split())
    if nmi == 0:
        break

    # Read m elements into the data array
    data = list(map(int, input().split()))

    # Initialize variables to track the maximum difference and the answer index
    ma = 0  # Maximum difference found
    ans = 0  # Index of the element that gives the maximum difference

    # Loop through the specified range from nmi-1 to nma-1
    for i in range(nmi - 1, nma - 1):
        # Check if the current difference is greater than the maximum found so far
        if ma <= data[i] - data[i + 1]:
            ans = i + 1  # Update the answer index
            ma = data[i] - data[i + 1]  # Update the maximum difference

    # Output the index of the element that produced the maximum difference
    print(ans)
