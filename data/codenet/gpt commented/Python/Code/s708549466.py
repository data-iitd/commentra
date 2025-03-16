# Read the number of elements (N) and the threshold value (x) from input
N, x = map(int, input().split())

# Read the list of integers (a) from input
a = list(map(int, input().split()))

# Initialize a counter to keep track of the total excess amount
cnt = 0

# Iterate through the list starting from the second element
for i in range(1, N):
    # Calculate the sum of the current and previous elements
    tmp = a[i - 1] + a[i]
    
    # Check if the sum exceeds the threshold value (x)
    if tmp > x:
        # Determine if the excess can be absorbed by the previous element
        if tmp - x > a[i]:
            # If not, adjust the previous element and set the current element to zero
            a[i - 1] = tmp - a[i] - x
            a[i] = 0
        else:
            # Otherwise, reduce the current element by the excess amount
            a[i] = a[i] - (tmp - x)
        
        # Increment the counter by the excess amount
        cnt += tmp - x

# Print the total excess amount that was counted
print(cnt)
