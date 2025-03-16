#######
# Code
#######

# Define the number of elements 'n' and the modulus 'm' in the list 'l'
n, m = map(int, input().split())

# Initialize an empty list 'l2' to store the quotient of each element in 'l' divided by 'm'
l2 = []

# Iterate through each element 'i' in the list 'l'
for i in l:
    # Check if the element 'i' is divisible by 'm'. If yes, append the quotient (integer division) to 'l2'. If not, append the quotient plus one.
    if i % m == 0:
        l2.append(i // m)
    else:
        l2.append(int(i // m + 1))

# Find the maximum quotient in 'l2'
mx = max(l2)

# Iterate through each index 'i' from 0 to 'n-1' in the list 'l2'
for i in range(n):
    # Check if the quotient at index 'i' in 'l2' is equal to the maximum quotient 'mx'. If yes, store the index 'i' in the variable 'ind'.
    if l2[i] == mx:
        ind = i

# Print the index 'ind' plus one (since the indices in Python start from 0)
print(ind + 1)
