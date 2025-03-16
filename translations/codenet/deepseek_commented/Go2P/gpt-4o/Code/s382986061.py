N, K = map(int, input().split())  # Read the values of N and K
as_map = {i: 0 for i in range(1, N + 1)}  # Create a dictionary to keep track of the occurrences of each element

for _ in range(K):
    d = int(input())  # Read the number of elements chosen on the i-th day
    for _ in range(d):
        a = int(input())  # Read the elements chosen on the i-th day
        as_map[a] += 1  # Increment the count of the chosen element in the dictionary

ans = sum(1 for v in as_map.values() if v == 0)  # Count unchosen elements
print(ans)  # Print the number of unchosen elements
# <END-OF-CODE>
