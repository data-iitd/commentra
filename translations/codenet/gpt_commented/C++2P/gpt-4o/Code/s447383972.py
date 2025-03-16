def read():
    # Function to read a long long integer from input
    return int(input().strip())

def writeln(x):
    # Function to write a long long integer followed by a newline
    print(x)

N = 200010  # Define a constant for the maximum size of the array
a = [0] * N  # Declare an array
q = [0] * N  # Declare an array for duplicates
tot = 0  # Initialize total duplicates count

n = read()  # Read the number of elements
for i in range(1, n + 1):
    a[i] = read()  # Read the elements into the array a

a[1:n + 1] = sorted(a[1:n + 1])  # Sort the array in non-decreasing order

# Identify duplicates and store them in array q
i = 1
while i <= n:
    if a[i] == a[i + 1]:
        q[tot + 1] = a[i]  # Store the duplicate
        tot += 1  # Increment the count of duplicates
        i += 1  # Skip the next element
    i += 1

# Output the product of the last two duplicates found
if tot >= 2:
    writeln(q[tot] * q[tot - 1])

# <END-OF-CODE>
