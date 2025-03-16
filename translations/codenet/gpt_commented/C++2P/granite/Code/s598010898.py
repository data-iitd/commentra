
# Read the number of elements
n = int(input())

# Input the first array 'a'
a = list(map(int, input().split()))

# Input the second array 'b' and calculate the sum of positive differences
sum = 0
for i in range(n):
    b = int(input())
    if a[i] - b > 0:
        sum += a[i] - b

# Output the final sum of positive differences
print(sum)
