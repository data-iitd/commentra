#######
# Code
#######

# Define the number of elements in the list 'a' and the target sum 'x'
N, x = map(int, input().split())

# Initialize an empty list 'a' with the given size 'N' and fill it with integers
a = [0] * N
a = list(map(int, input().split()))

# Initialize a counter 'cnt' to 0
cnt = 0

# Iterate through the list 'a' starting from the second element
for i in range(1, N):
    # Calculate the sum of the previous and current elements
    tmp = a[i - 1] + a[i]
    
    # Check if the sum is greater than the target sum 'x'
    if tmp > x:
        # Check if the difference between the sum and the target sum is greater than the current element
        if tmp - x > a[i]:
            # Subtract the difference from the previous element and set the current element to 0
            a[i - 1] = tmp - a[i] - x
            a[i] = 0
        else:
            # Subtract the difference from the current element
            a[i] = a[i] - (tmp - x)
        # Increment the counter by the difference
        cnt += tmp - x

# Print the final counter value
print(cnt)
