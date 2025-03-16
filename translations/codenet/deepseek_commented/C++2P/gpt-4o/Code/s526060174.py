# 1. Input Reading: Declare variables to store the number of sets and the maximum element value.
n, m = map(int, input().split())  # Read the number of sets and the maximum element value.
# 2. Array Initialization: Initialize an array to count occurrences of each element from 1 to 30.
x = [0] * 31  # Initialize a list to count occurrences of each element.

# 3. Nested Loops for Input: Loop through each set.
for _ in range(n):
    k = int(input())  # Read the number of elements in the current set.
    # Loop through each element in the current set.
    for _ in range(k):
        a = int(input())  # Read an element.
        x[a] += 1  # Increment the count of the element in the list x.

# 4. Counting Elements: Initialize a variable to store the count of elements that appear in every set.
ans = 0
# Loop through each element from 1 to m.
for i in range(1, m + 1):
    if x[i] == n:  # Check if the element appears in every set.
        ans += 1  # Increment the count if the condition is met.

# 5. Output the Result: Print the final count of elements that appear in every set.
print(ans)  # Output the result
# <END-OF-CODE>
