
# Create a Scanner object for user input
input = Scanner(sys.stdin)

# Read two integers n and m from user input
n = int(input.next())
m = int(input.next())

# Initialize an array of size m to hold the results
a = [0] * m

# Check if n is divisible by m
if n % m == 0:
    # If divisible, fill the array with equal parts
    for i in range(0, m):
        a[i] = n / m
else:
    # If not divisible, calculate the base value for each part
    sub = n / m
    for i in range(0, m):
        a[i] = sub

    # Calculate the remainder that needs to be distributed
    test = n - (sub * m)
    count = 0

    # Distribute the remainder across the first few elements of the array
    for i in range(0, test):
        a[count] = a[count] + 1
        count = count + 1

        # Wrap around if count exceeds the array length
        if count >= m:
            count = 0

# Print the array in reverse order
for i in range(m - 1, -1, -1):
    print(a[i], end=' ')

# 