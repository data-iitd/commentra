
# Read the number of elements and the threshold value from user input
n, k = map(int, input().split())

# Initialize the counter to zero
cnt = 0

# Loop through each element, decrementing n until it reaches zero
while n > 0:
    h = int(input())
    
    # Check if the current element is greater than or equal to the threshold
    if h >= k:
        # Increment the counter if the condition is met
        cnt += 1
    
    # Decrement the counter by one
    n -= 1

# Output the final count of elements that met or exceeded the threshold
print(cnt)

# End of code