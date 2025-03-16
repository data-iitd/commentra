# Importing the necessary package for input
n = int(input())  # Read the size of the array
arr = list(map(int, input().split()))  # Create an array of size n and read n integers
sum_arr = sum(arr)  # Calculate the sum of the array

c = 0  # Initialize count of valid elements to remove
indices = []  # Create a list to store the indices of valid elements

# Iterate through the array arr to find elements that can be removed
for i in range(n):
    # Check if removing the current element keeps the average unchanged
    if (sum_arr - arr[i]) % (n - 1) == 0 and (sum_arr - arr[i]) // (n - 1) == arr[i]:
        c += 1  # Increment the count
        indices.append(i + 1)  # Append the index (plus one) to the list

# Print the count of valid elements and the indices of these elements
print(c)
print(" ".join(map(str, indices)))

# <END-OF-CODE>
