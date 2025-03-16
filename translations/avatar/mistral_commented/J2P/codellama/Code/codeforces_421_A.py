# Import necessary libraries
import math
import sys

# Create a Scanner object to read input
sc = sys.stdin

# Declare and initialize variables
n, a, b = map(int, sc.readline().split())

# Create ArrayList objects to store the lists
list1 = []
list2 = []

# Read and store the elements of the first and second lists
for i in range(a):
    list1.append(int(sc.readline()))
for i in range(b):
    list2.append(int(sc.readline()))

# Iterate through the input array and print the corresponding number based on the presence of the element in list1
for i in range(n):
    if i + 1 in list1:
        print(1, end=" ")
    else:
        print(2, end=" ")

# Close the Scanner object
sc.close()

