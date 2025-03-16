
# Read the number of elements in array x
n = int(input())

# Read n elements into array x
x = list(map(int, input().split()))

# Read the number of queries
q = int(input())

# Read q elements into array y
y = list(map(int, input().split()))

# Initialize sum to count how many elements in y are found in x
sum = 0

# Check each element in y against all elements in x
for i in range(q):
    for j in range(n):
        # If a match is found, increment sum and break the inner loop
        if y[i] == x[j]:
            sum = sum + 1
            break

# Output the total count of matches found
print(sum)

