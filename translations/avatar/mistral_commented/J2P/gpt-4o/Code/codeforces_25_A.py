# Importing the necessary module for user input
n = int(input())  # Reading the number of elements in the array from user input
array = [0] * (n + 1)  # Creating an array of size n+1 to store the input elements

# Reading the elements of the array from user input
for i in range(1, n + 1):
    array[i] = int(input())  # Reading the i-th element of the array

odd = 0
even = 0
odd_ind = 0
even_ind = 0  # Initializing variables for counting odd and even elements and their indices

# Counting the number of odd and even elements and storing their indices
for i in range(1, n + 1):
    if array[i] % 2 == 0:  # If the current element is even
        even += 1  # Increment the count of even elements
        even_ind = i  # Store the index of the current even element
    else:  # If the current element is odd
        odd += 1  # Increment the count of odd elements
        odd_ind = i  # Store the index of the current odd element

# Determining the output based on the count of odd and even elements
if odd > even:  # If there are more odd elements than even elements
    print(even_ind)  # Print the index of the last even element
else:  # If there are more even elements than odd elements
    print(odd_ind)  # Print the index of the last odd element

# <END-OF-CODE>
