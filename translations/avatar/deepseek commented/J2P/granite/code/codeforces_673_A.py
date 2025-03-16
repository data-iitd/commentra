

n = int(input()) # Read the number of elements in the list `a`
a = [] # Initialize an empty list `a`

for i in range(n): # Read each integer value and add it to the list `a`
    value = int(input())
    a.append(value)

result = 0
pos = 0
flag = 0

if a[0] > 15: # If the first element is greater than 15, set result to 15
    result = 15
else:
    for i in range(1, n): # Find the position where the difference is greater than 15
        if a[i] - a[i-1] > 15:
            pos = i - 1
            flag = 1
            break
    if flag == 1: # Set result to the element at pos plus 15
        result = a[pos] + 15
    else: # Otherwise, set result to the last element plus 15
        result = a[n-1] + 15

if result > 90: # If result is greater than 90, set it to 90
    result = 90

print(result) # Print the final result
