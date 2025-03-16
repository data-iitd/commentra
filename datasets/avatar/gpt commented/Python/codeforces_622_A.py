# Importing necessary constants from the cmd module
from cmd import IDENTCHARS

# Taking input from the user and converting it to an integer
n = int(input())

# Initializing left and right pointers for binary search
l = 1
r = n

# Performing binary search to find the largest integer 'l' such that the sum of the first 'l' integers is less than or equal to 'n'
while (l < r):
    # Calculating the midpoint of the current range
    mid = l + (r - l) // 2
    
    # Calculating the sum of the first 'mid' integers using the formula: sum = mid * (mid + 1) / 2
    idxcnt = mid * (mid + 1) / 2
    
    # If the sum is less than 'n', move the left pointer up to search in the right half
    if (idxcnt < n):
        l = mid + 1
    # Otherwise, move the right pointer down to search in the left half
    else:
        r = mid

# Adjusting 'l' to get the largest valid integer
l -= 1

# Calculating the sum of the first 'l' integers
idxcnt = l * (l + 1) / 2

# Printing the difference between 'n' and the sum of the first 'l' integers
print(int(n - idxcnt))
