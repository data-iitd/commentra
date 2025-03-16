# Take an integer 'n' as input
n = int(input())

# Create a list 'lst' of 'n' integers taken as input
lst = list(map(int, input().split()))

# Sort the list 'lst' in ascending order
lst.sort()

# Reverse the sorted list 'lst'
lst.reverse()

# Initialize odd_digits counter 'od' to 0
od = 0

# Iterate through each integer 'i' in the list 'lst'
for i in lst:
    # If the integer 'i' has an odd number of bits (1 in binary representation), increment 'od' counter
    if (i & 1):
        od += 1

# Initialize sum and ok variables
sum = 0
ok = 0

# Iterate through each index 'i' in the range of 'n'
for i in range(n):
    # If the integer at index 'i' in the list 'lst' is even, add it to the sum 'sum'
    if (lst[i] % 2 == 0):
        sum += lst[i]
    # If the integer at index 'i' in the list 'lst' is odd and either 'ok' is True or 'od' is greater than 1, add it to the sum 'sum' and toggle 'ok'
    else:
        if (ok or od > 1):
            sum += lst[i]
            od -= 1
            ok = not ok

# Print the final sum
print(sum)
