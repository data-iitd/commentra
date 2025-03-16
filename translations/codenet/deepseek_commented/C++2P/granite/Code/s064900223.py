
n = int(input()) # Step 4: Read the input value for `n`
p = [0] * n # Step 5: Create a list `p` of size `n`
for i in range(n): # Step 6: Read values into the list `p`
    p[i] = int(input())
ans = 0 # Step 7: Initialize `ans` to 0
for i in range(n - 1): # Step 8: Loop through the list `p`
    if p[i] == i + 1: # If the current element `p[i]` is equal to `i+1`
        p[i + 1] = p[i] # Set the next element `p[i+1]` to `p[i]`
        ans += 1 # Increment `ans`
if p[n - 1] == n: # Step 9: Check the last element
    ans += 1 # Increment `ans` if the last element is equal to `n`
print(ans) # Step 10: Output the result
