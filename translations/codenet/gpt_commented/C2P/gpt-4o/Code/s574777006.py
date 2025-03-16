# Declare variables
n = int(input())

# Read n elements into list x
x = list(map(int, input().split()))

# Read the number of queries
q = int(input())

# Read q elements into list y
y = list(map(int, input().split()))

# Initialize sum to count how many elements in y are found in x
sum_matches = 0
for i in range(q):
    # Check each element in y against all elements in x
    for j in range(n):
        # If a match is found, increment sum and break the inner loop
        if y[i] == x[j]:
            sum_matches += 1
            break

# Output the total count of matches found
print(sum_matches)

# <END-OF-CODE>
