import sys

# Reading input from the user
n = int(input())
k = int(input())

i = 1
req = 1

# Loop to decrement k until it is no longer possible
while k - req >= 0:
    # Check if k can be decremented by req
    if k - req >= 0:
        k = k - req
    else:
        break
    
    i += 1
    
    # Determine the next req value based on the current value of i
    if i % n!= 0:
        req = i % n
    else:
        req = n

# Output the final value of k after all possible decrements
print(k)

# 