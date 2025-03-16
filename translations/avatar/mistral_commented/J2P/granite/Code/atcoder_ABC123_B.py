
import sys

a = list(map(int, input().split())) # Reading input elements of array 'a' and storing them in a list
r = [i % 10 for i in a] # Creating a list 'r' to store the remainders of the elements in array 'a'

map = {} # Creating an empty dictionary to store integer keys and their corresponding integer values

# Storing the complements of the remainders as keys and the corresponding elements of array 'a' as values in the dictionary
for i in range(len(a)):
    if r[i]!= 0:
        map[10 - r[i]] = a[i]

ans = 0 # Initializing 'ans' to zero

# Checking if the dictionary is empty
if len(map) == 0:
    for i in range(len(a)): # Iterating through the array 'a'
        ans += a[i] # Adding the 'i'th element of array 'a' to the sum 'ans'
    print(ans) # Printing the sum of all elements in array 'a'
    sys.exit() # Exiting the program if the dictionary is empty

last = list(map.keys())[-1] # Getting the last key (complement) from the dictionary and finding its corresponding value (the last element of array 'a')
idx = 0 # Initializing 'idx' to zero

# Finding the index of the last element in array 'a'
for i in range(len(a)):
    if a[i] == last: # Checking if the 'i'th element of array 'a' is equal to the last element
        idx = i # If true, assigning the index to 'idx'
        break # Exiting the loop

# Calculating the sum of all elements in array 'a' except the last one
for i in range(len(a)):
    if i!= idx: # Checking if the current index is not equal to 'idx'
        if a[i] % 10 == 0: # Checking if the 'i'th element of array 'a' is a multiple of 10
            ans += a[i] # If true, adding it to the sum 'ans'
        else: # If the 'i'th element of array 'a' is not a multiple of 10
            ans += a[i] + (10 - r[i]) # Adding the 'i'th element of array 'a' and its complement to the sum 'ans'

# Adding the last element of array 'a' to the sum 'ans'
ans += last

print(ans) # Printing the final sum

