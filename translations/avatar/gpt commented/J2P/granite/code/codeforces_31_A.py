
```python
# Read the number of elements in the array
n = int(input())

# Initialize a flag to indicate if a valid triplet is found
f = 0

# Create an array to store the input integers
a = []

# Read n integers from the input and store them in the array
for i in range(n):
    a.append(int(input()))

# Initialize variables for indexing
k = 0
j = 0
i = 0

# Iterate through each element in the array
for k in range(n):
    # Store the current element to check against pairs
    t = a[k]

    # Check for pairs in the array that sum up to the current element
    for i in range(n):
        for j in range(n - 1):
            # Ensure we are not using the same element twice
            if i!= j and t == (a[i] + a[j]):
                # Set the flag to indicate a valid triplet is found
                f = 1
                break
        # Break out of the loop if a valid pair is found
        if f == 1:
            break

# Output the result: indices of the triplet or -1 if not found
if f == 1:
    print(str(k + 1) + " " + str(j + 1) + " " + str(i + 1))
else:
    print("-1")
```

