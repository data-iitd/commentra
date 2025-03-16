n, k = map(int, input().split())  # Read the number of elements and the subarray size
vec = list(map(int, input().split()))  # Read each element and store it in a list
vec.sort()  # Sort the list in ascending order

ans = float('inf')  # Initialize the answer with a large number

for i in range(n - k + 1):  # Iterate through the sorted list
    diff = vec[i + k - 1] - vec[i]  # Calculate the difference between the max and min in the subarray
    if diff < ans:  # Update the answer if the current difference is smaller
        ans = diff

print(ans)  # Output the minimum difference
# <END-OF-CODE>
