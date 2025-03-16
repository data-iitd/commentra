# Take two integers as input and store them in list 'l' and 'r' respectively
l, r = [int(x) for x in input().split()]

# Initialize current number to 'r'
curr = r

# Initialize sum variable 's' to 0
s = 0

# While 'curr' is not zero, perform the following operations
while curr:
    # Increment the sum 's' by 1
    s += 1
    
    # Calculate the power of 10 raised to the value of 's' and store it in 'first'
    first = 10 ** s
    
    # Calculate half of 'first' and store it in 'second'
    second = first // 2
    
    # Initialize 'ans' with a negative value
    ans = -1
    
    # Iterate through the list containing 'l', 'r', 'first', and 'second'
    for i in [l, r, first, second]:
        # If 'i' lies within the range of 'l' and 'r', update 'curr' and 'rev'
        if i >= l and i <= r:
            curr = i
            rev = ''
            # Reverse the digits of 'curr' and store it in 'rev'
            for k in str(curr):
                rev += str(9 - int(k))
            
            # Update 'ans' with the maximum value of the current 'ans' and the product of 'curr' and the reversed number
            ans = max(ans, int(rev) * curr)

# Print the final answer
print(ans)
