# Read an integer input which represents the number of elements
n = int(input())

# Read a line of input, split it into individual elements, convert them to integers,
# and create a list that contains 1 for odd numbers and 0 for even numbers
list = [int(x) % 2 for x in input().split()]

# Check if there is exactly one odd number in the list
if sum(list) == 1:
    # If there is one odd number, print its position (1-based index)
    print(list.index(1) + 1)
else:
    # If there are no odd numbers, print the position of the first even number (1-based index)
    print(list.index(0) + 1)
