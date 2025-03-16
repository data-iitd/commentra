
N, K = map(int, input().split()) # Read the values of N and K
as = {i: 0 for i in range(1, N+1)} # Create a dictionary to keep track of the occurrences of each element
for i in range(K):
    d = int(input()) # Read the number of elements chosen on the i-th day
    for j in range(d):
        a = int(input()) # Read the elements chosen on the i-th day
        as[a] += 1 # Increment the count of the chosen element in the dictionary
ans = sum(1 for v in as.values() if v == 0) # Count the number of unchosen elements
print(ans) # Print the number of unchosen elements
