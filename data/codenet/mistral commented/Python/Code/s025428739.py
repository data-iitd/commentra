
# Define two variables `A` and `B` and assign them the values obtained from user input
A, B = map(int, input().split())

# Create an empty list `lst` to store the results of our calculations
lst = []

# Append the sum of `A` and `B` to the list `lst`
lst.append(A + B)

# Append the difference of `A` and `B` to the list `lst`
lst.append(A - B)

# Append the product of `A` and `B` to the list `lst`
lst.append(A * B)

# Use the `max()` function to find the maximum value in the list `lst` and print it
print(max(lst))