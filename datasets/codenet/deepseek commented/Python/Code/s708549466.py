N, x = map(int, input().split())  # Reading N and x from input
a = list(map(int, input().split()))  # Reading the list a from input
cnt = 0  # Initializing the counter to zero

# Loop through the elements of the list a starting from the second element
for i in range(1, N):
    tmp = a[i - 1] + a[i]  # Calculate the sum of the current and previous element
    if tmp > x:  # Check if the sum exceeds x
        if tmp - x > a[i]:  # Check if reducing the previous element would result in a larger reduction
            a[i - 1] = tmp - a[i] - x  # Adjust the previous element
            a[i] = 0  # Set the current element to zero
        else:
            a[i] = a[i] - (tmp - x)  # Reduce the current element by the excess amount
        cnt += tmp - x  # Update the counter with the excess amount

print(cnt)  # Output the result