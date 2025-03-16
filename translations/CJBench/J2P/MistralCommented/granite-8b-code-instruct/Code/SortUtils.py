

import sys

def swap(array, i, j):
    if i!= j:
        # Temporary variable to store the element at index i
        temp = array[i]

        # Assigns the element at index j to index i
        array[i] = array[j]

        # Assigns the element stored in the temporary variable to index j
        array[j] = temp

# Reads the number of elements in the array from the standard input
n = int(input())

# Creates an Integer array with the given size
array = [None] * n

# Reads the elements of the array from the standard input and stores them in the array
for i in range(n):
    array[i] = int(input())

# Reads the indices i and j of the two elements to be swapped from the standard input
i = int(input())
j = int(input())

# Swaps the elements at the given indices in the array
swap(array, i, j)

# Prints the swapped array
print(*array, sep=" ")

# Checks if the array is sorted in ascending order
def is_sorted(array):
    for i in range(1, len(array)):
        # Checks if the current element is less than the previous one
        if array[i] < array[i - 1]:
            return False
    return True

# Prints whether the array is sorted or not
print(is_sorted(array))

# Reads the left and right indices of the subarray to be flipped from the standard input
left = int(input())
right = int(input())

# Flips the subarray from left to right in the array
array[left:right + 1] = reversed(array[left:right + 1])

# Prints the flipped array
print(*array, sep=" ")

# Reads the number of elements in the list from the standard input
n = int(input())

# Creates an Integer list with the given size
list_to_print = [None] * n

# Reads the elements of the list from the standard input and stores them in the list
for i in range(n):
    list_to_print[i] = int(input())

# Prints the list to the standard output, separated by a space
print(*list_to_print, sep=" ")

# Checks if the list is sorted in ascending order
def is_sorted(list_to_check):
    for i in range(1, len(list_to_check)):
        # Checks if the current element is less than the previous one
        if list_to_check[i] < list_to_check[i - 1]:
            return False
    return True

# Prints whether the list is sorted or not
print(is_sorted(list_to_print))

# Reads the left and right indices of the sublist to be reversed from the standard input
left = int(input())
right = int(input())

# Reverses the sublist from left to right in the list
list_to_print[left:right + 1] = reversed(list_to_print[left:right + 1])

# Prints the reversed list
print(*list_to_print, sep=" ")

# Reads the number of elements in the list from the standard input
n = int(input())

# Creates an Integer list with the given size
list_to_print = [None] * n

# Reads the elements of the list from the standard input and stores them in the list
for i in range(n):
    list_to_print[i] = int(input())

# Prints the list to the standard output, separated by a space
print(*list_to_print, sep=" ")

# Checks if the list is sorted in ascending order
def is_sorted(list_to_check):
    for i in range(1, len(list_to_check)):
        # Checks if the current element is less than the previous one
        if list_to_check[i] < list_to_check[i - 1]:
            return False
    return True

# Prints whether the list is sorted or not
print(is_sorted(list_to_print))

# Reads the left and right indices of the sublist to be reversed from the standard input
left = int(input())
right = int(input())

# Reverses the sublist from left to right in the list
list_to_print[left:right + 1] = reversed(list_to_print[left:right + 1])

# Prints the reversed list
print(*list_to_print, sep=" ")

# Reads the number of elements in the list from the standard input
n = int(input())

# Creates an Integer list with the given size
list_to_print = [None] * n

# Reads the elements of the list from the standard input and stores them in the list
for i in range(n):
    list_to_print[i] = int(input())

# Prints the list to the standard output, separated by a space
print(*list_to_print, sep=" ")

# Checks if the list is sorted in ascending order
def is_sorted(list_to_check):
    for i in range(1, len(list_to_check)):
        # Checks if the current element is less than the previous one
        if list_to_check[i] < list_to_check[i - 1]:
            return False
    return True

# Prints whether the list is sorted or not
print(is_sorted(list_to_print))

# Reads the left and right indices of the sublist to be reversed from the standard input
left = int(input())
right = int(input())

# Reverses the sublist from left to right in the list
list_to_print[left:right + 1] = reversed(list_to_print[left:right + 1])

# Prints the reversed list
print(*list_to_print, sep=" ")

# Reads the number of elements in the list from the standard input
n = int(input())

# Creates an Integer list with the given size
list_to_print = [None] * n

# Reads the elements of the list from the standard input and stores them in the list
for i in range(n):
    list_to_print[i] = int(input())

# Prints the list to the standard output, separated by a space
print(*list_to_print, sep=" ")

# Checks if the list is sorted in ascending order
def is_sorted(list_to_check):
    for i in range(1, len(list_to_check)):
        # Checks if the current element is less than the previous one
        if list_to_check[i] < list_to_check[i - 1]:
            return False
    return True

# Prints whether the list is sorted or not
print(is_sorted(list_to_print))

# Reads the left and right indices of the sublist to be reversed from the standard input
left = int(input())
right = int(input())

# Reverses the sublist from left to right in the list
list_to_print[left:right + 1] = reversed(list_to_print[left:right + 1])

# Prints the reversed list
print(*list_to_print, sep=" ")

# Reads the number of elements in the list from the standard input
n = int(input())

# Creates an Integer list with the given size
list_to_print = [None] * n

# Reads the elements of the list from the standard input and stores them in the list
for i in range(n):
    list_to_print[i] = int(input())

# Prints the list to the standard output, separated by a space
print(*list_to_print, sep=" ")

# Checks if the list is sorted in ascending order
def is_sorted(list_to_check):
    for i in range(1, len(list_to_check)):
        # Checks if the current element is less than the previous one
        if list_to_check[i] < list_to_check[i - 1]:
            return False
    return True

# Prints whether the list is sorted or not
print(is_sorted(list_to_print))

# Reads the left and right indices of the sublist to be reversed from the standard input
left = int(input())
right = int(input())

# Reverses the sublist from left to right in the list
list_to_print[left:right + 1] = reversed(list_to_print[left:right + 1])

# Prints the reversed list
print(*list_to_print, sep=" ")

# Reads the number of elements in the list from the standard input
n = int(input())

# Creates an Integer list with the given size
list_to_print = [None] * n

# Reads the elements of the list from the standard input and stores them in the list
for i in range(n):
    list_to_print[i] = int(input())

# Prints the list to the standard output, separated by a space
print(*list_to_print, sep=" ")

# Checks if the list is sorted in ascending order
def is_sorted(list_to_check):
    for i in range(1, len(list_to_check)):
        # Checks if the current element is less than the previous one
        if list_to_check[i] < list_to_check[i - 1]:
            return False
    return True

# Prints whether the list is sorted or not
print(is_sorted(list_to_print))

# Reads the left and right indices of the sublist to be reversed from the standard input
left = int(input())
right = int(input())

# Reverses the sublist from left to right in the list
list_to_print[left:right + 1] = reversed(list_to_print[left:right + 1])

# Prints the reversed list
print(*list_to_print, sep=" ")

# Reads the number of elements in the list from the standard input
n = int(input())

# Creates an Integer list with the given size
list_to_print = [None] * n

# Reads the elements of the list from the standard input and stores them in the list
for i in range(n):
    list_to_print[i] = int(input())

# Prints the list to the standard output, separated by a space
print(*list_to_print, sep=" ")

# Checks if the list is sorted in ascending order
def is_sorted(list_to_check):
    for i in range(1, len(list_to_check)):
        # Checks if the current element is less than the previous one
        if list_to_check[i] < list_to_check[i - 1]:
            return False
    return True

# Prints whether the list is sorted or not
print(is_sorted(list_to_print))

# Reads the left and right indices of the sublist to be reversed from the standard input
left = int(input())
right = int(input())

# Reverses the sublist from left to right in the list
list_to_print[left:right + 1] = reversed(list_to_print[left:right + 1])

# Prints the reversed list
print(*list_to_print, sep=" ")

# Reads the number of elements in the list from the standard input
n = int(input())

# Creates an Integer list with the given size
list_to_print = [None] * n

# Reads the elements of the list from the standard input and stores them in the list
for i in range(n):
    list_to_print[i] = int(input())

# Prints the list to the standard output, separated by a space
print(*list_to_print, sep=" ")

# Checks if the list is sorted in ascending order
def is_sorted(list_to_check):
    for i in range(1, len(list_to_check)):
        # Checks if the current element is less than the previous one
        if list_to_check[i] < list_to_check[i - 1]:
            return False
    return True

# Prints whether the list is sorted or not
print(is_sorted(list_to_print))

# Reads the left and right indices of the sublist to be reversed from the standard input
left = int(input())
right = int(input())

# Reverses the sublist from left to right in the list
list_to_print[left:right + 1] = reversed(list_to_print[left:right