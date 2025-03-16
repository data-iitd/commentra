
n, m = map(int, input().split()) # 1. Input Reading: Declare variables to store the number of sets and the maximum element value.
x = [0] * 31 # 2. Array Initialization: Initialize an array to count occurrences of each element from 1 to 30.
for i in range(n): # 3. Nested Loops for Input: Loop through each set.
  k = int(input()) # Read the number of elements in the current set.
  for a in map(int, input().split()): # Loop through each element in the current set.
    x[a] += 1 # Increment the count of the element in the array x.
ans = 0 # 4. Counting Elements: Initialize a variable to store the count of elements that appear in every set.
for i in range(1, m + 1): # Loop through each element from 1 to m.
  if x[i] == n: # Check if the element appears in every set.
    ans += 1 # Increment the count if the condition is met.
print(ans) # 5. Output the Result: Print the final count of elements that appear in every set.
