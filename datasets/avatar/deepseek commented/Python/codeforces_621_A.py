
n = int(input())  # Read the number of elements in the list
lst = list(map(int, input().split()))  # Read the list of integers
lst.sort()  # Sort the list in ascending order
lst.reverse()  # Reverse the list to get descending order

# Initialize a counter for odd numbers
od = 0
for i in lst:
    if i & 1:  # Check if the number is odd
        od += 1

# Initialize sum to accumulate the result
sum = 0
ok = 0  # Initialize a flag to track if an odd number has been added

# Iterate through the list to process each number
for i in range(n):
    if lst[i] % 2 == 0:  # Check if the number is even
        sum += lst[i]  # Add even numbers to sum
    else:
        if ok or od > 1:  # Check if an odd number can be added
            sum += lst[i]  # Add odd number to sum
            od -= 1  # Decrement the count of odd numbers
            ok = not ok  # Toggle the flag

print(sum)  # Print the final sum

