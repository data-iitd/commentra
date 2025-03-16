# Step 1: Read the value of n, which represents the number of elements in the array.
n = int(input())
# Initialize sum to store the total difference.
sum = 0
# Step 2: Dynamically allocate memory for an array 'a' of size n.
a = [0]*n
# Step 3: Read n elements into the array 'a'.
for i in range(n):
    a[i] = int(input())
# Step 4: Iterate through the array and calculate the sum of the differences between consecutive elements, updating the array 'a' to ensure each element is at least as large as the previous one.
for i in range(1,n):
    if a[i-1]>a[i]:
        sum += a[i-1]-a[i] # Add the difference to the sum.
        a[i] = a[i-1] # Update the current element to be at least as large as the previous one.
# Step 5: Print the calculated sum.
print(sum)

