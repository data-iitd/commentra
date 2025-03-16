import numpy as np  # Importing the NumPy library for numerical operations

# Taking input for the number of elements
N = int(input("Enter the number of elements: "))  

# Taking input for the elements and converting them into a list of integers
n = [int(x) for x in input("Enter the elements separated by spaces: ").split()]  

# Converting the list of integers into a NumPy array for easier manipulation
n = np.array(n)  

# Initializing a counter 'a' to count the number of elements that are less than the current element
a = 1  

# Initializing 'pos' to keep track of the position of the last element that was smaller
pos = 0  

# Looping through the array starting from the second element
for i in range(1, N):  
    # Checking if the current element is smaller than the element at 'pos'
    if n[pos] > n[i]:  
        a += 1  # Incrementing the counter if the condition is met
        pos = i  # Updating 'pos' to the current index

# Printing the final count of elements that were smaller than the previous ones
print(a)  
