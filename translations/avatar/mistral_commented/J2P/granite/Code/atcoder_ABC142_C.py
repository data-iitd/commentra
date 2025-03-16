
import sys  # Importing the sys module for using input() function

N = int(input())  # Reading the number of elements from the user input

idorder = {}  # Declaring an empty dictionary 'idorder' to store the indices of the elements

for i in range(1, N + 1):  # Reading the elements and storing their corresponding indices in the dictionary
    A = int(input())
    idorder[A] = i

for i in range(1, N + 1):  # Printing the indices of the elements in the order they were read
    print(idorder[i], end=" ")

print("