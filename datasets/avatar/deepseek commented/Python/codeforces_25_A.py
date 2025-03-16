
n = int(input())  # Take an integer input representing the number of elements
list = [int(x) % 2 for x in input().split()]  # Split the input string, convert to integers, and calculate remainders modulo 2

# Check if the sum of the list is 1
if sum(list) == 1:
    print(list.index(1) + 1)  # Print the index of the first occurrence of 1 (adjusted for 1-based indexing)
else:
    print(list.index(0) + 1)  # Print the index of the first occurrence of 0 (adjusted for 1-based indexing)

