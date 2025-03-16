

n = int(input()) # Read the number of elements in the array
a = list(map(int, input().split())) # Read the elements of the array

f = 0 # Flag to indicate if the triplet is found
k = 0 # Initialize index k

# Outer loop to iterate over each element as a potential a[k]
for k in range(n):
    t = a[k] # Current element as t
    
    # Inner loops to find two indices i and j such that a[i] + a[j] = t
    for i in range(n):
        for j in range(n-1):
            if i!= j and t == (a[i] + a[j]):
                f = 1 # Set flag to 1 if triplet is found
                break # Break out of the inner loop
        if f == 1:
            break # Break out of the outer loop if triplet is found

# Check if a triplet was found and print the result
if f == 1:
    print(k+1, end=" ")
    for i in range(n):
        if a[i] == t:
            print(i+1, end=" ")
            break
    for j in range(n):
        if a[j] == t:
            print(j+1)
            break
else:
    print(-1)

