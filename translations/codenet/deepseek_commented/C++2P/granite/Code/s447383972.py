
# Step 7: Main function
n = int(input()) # Read the size of the array.
a = list(map(int, input().split())) # Read the elements of the array.
a.sort() # Sort the array.
q = []
for i in range(n):
    if i == n - 1 or a[i]!= a[i + 1]:
        q.append(a[i])
print(q[-1] * q[-2]) # Print the product of the two largest distinct elements.

