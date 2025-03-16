# Function to read input as a list of integers
def _input ():
    return list(map(int, input().split()))

# Read number of elements 'n' and size 'm' of the list 'lst'
n, m = _input()

# Initialize an empty dictionary 'l' to store the frequency of each element
lst = list(_input())
l = {}

# Iterate through each element in the list 'lst'
for i in range(n):
    # If the current element is not already present in the dictionary 'l'
    if lst[i] not in l:
        # Add the current element to the dictionary 'l' with a frequency of 1
        l[lst[i]] = 1
    # If the current element is already present in the dictionary 'l'
    else:
        # Increment the frequency of the current element in the dictionary 'l'
        l[lst[i]] += 1

# Initialize result variable 'res' to 0
res = 0

# Iterate through each element in the list 'lst'
for i in range(n):
    # If the frequency of the current element in the dictionary 'l' is greater than 1
    if l[lst[i]] > 1:
        # Calculate the number of elements that have a smaller frequency than the current element
        # and add it to the result variable 'res'
        res += n - i - l[lst[i]]
        # Decrease the frequency of the current element in the dictionary 'l' by 1
        l[lst[i]] -= 1
    # If the frequency of the current element in the dictionary 'l' is equal to 1
    else:
        # Calculate the number of elements that have not been processed yet and add it to the result variable 'res'
        res += n - i - 1

# Print the final result
print(res)
