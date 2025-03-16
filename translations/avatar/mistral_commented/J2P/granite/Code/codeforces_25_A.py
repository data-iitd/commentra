
n = int(input("Enter the number of elements in the array: "))  # Reading the number of elements in the array from user input
array = [int(input("Enter element " + str(i+1) + ": ")) for i in range(n)]  # Reading the elements of the array from user input

odd = 0  # Initializing variables for counting odd and even elements
even = 0
odd_ind = 0  # Storing the index of the last odd element
even_ind = 0  # Storing the index of the last even element

# Counting the number of odd and even elements and storing their indices
for i in range(n):
    if array[i] % 2 == 0:  # If the current element is even
        even += 1  # Increment the count of even elements
        even_ind = i + 1  # Store the index of the current even element
    else:  # If the current element is odd
        odd += 1  # Increment the count of odd elements
        odd_ind = i + 1  # Store the index of the current odd element

# Determining the output based on the count of odd and even elements
if odd > even:  # If there are more odd elements than even elements
    print(even_ind)  # Print the index of the last even element
else:  # If there are more even elements than odd elements
    print(odd_ind)  # Print the index of the last odd element

