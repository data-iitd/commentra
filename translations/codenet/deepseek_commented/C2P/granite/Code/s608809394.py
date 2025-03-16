
# Read the size of the array
n = int(input())
# Declare an array of size n
a = []
# Read n integers and store them in the array a
for i in range(n):
    a.append(int(input()))
# Initialize t to 0, which will store the final sum of products
t = 0
# Outer loop to iterate over each element in the array a
for i in range(n):
    # Initialize s to 0, which will store the sum of products for the current element
    s = 0
    # Inner loop to iterate over each element in the array a, skipping the current element
    for j in range(n):
        if j <= i:
            continue # Skip the current element being processed by the outer loop
        # Calculate the product of the current element and the current element in the inner loop
        m = a[i] * a[j]
        # Add the product to the sum s
        s = s + m
    # Add the sum s to the final sum t
    t = t + s
# Print the final sum of products
print(t)
