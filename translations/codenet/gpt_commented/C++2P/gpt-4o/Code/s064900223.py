n = int(input())  # Input the size of the vector
p = list(map(int, input().split()))  # Initialize a list of size n and input the elements

ans = 0  # Initialize the answer counter to zero

# Loop through the list to check for specific conditions
for i in range(n - 1):
    # Check if the current element matches its expected position (1-based index)
    if p[i] == i + 1:
        p[i + 1] = p[i]  # Set the next element to the current element
        ans += 1  # Increment the answer counter

# Check if the last element matches its expected position
if p[n - 1] == n:
    ans += 1  # Increment the answer counter if the condition is met

print(ans)  # Output the final count of matches
# <END-OF-CODE>
