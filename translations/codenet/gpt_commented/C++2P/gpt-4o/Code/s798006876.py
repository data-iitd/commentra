# Define a constant for the maximum number of elements
MAX_N = 1000

# Array to hold input data
data = [0] * MAX_N

while True:
    # Read inputs m, nmi, and nma
    m, nmi, nma = map(int, input().split())
    if nmi == 0:
        break

    # Read m elements into the data array
    for i in range(m):
        data[i] = int(input())

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

# <END-OF-CODE>
