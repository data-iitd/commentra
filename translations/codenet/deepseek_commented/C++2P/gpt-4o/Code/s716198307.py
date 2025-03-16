# Step 1: Input the number of elements (n) and the array elements (a)
n = int(input())
a = list(map(int, input().split()))

# Step 2: Calculate the average of the array elements
avg = sum(a) / n

# Step 3: Find the element closest to the average
s = abs(a[0] - avg)
ans = 0
for i in range(1, n):
    if s > abs(a[i] - avg):
        s = abs(a[i] - avg)
        ans = i

# Step 4: Output the index of the closest element
print(ans)

# <END-OF-CODE>
