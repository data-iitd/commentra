# Read user input and assign it to the variable 'n'
n = int(input())

# Create a list 'list' with the same length as 'n'
# Each element in the list is the remainder of the corresponding input value divided by 2
list = [int(x) % 2 for x in input().split()]

# Check if the sum of all elements in the list is equal to 1
if sum(list) == 1:
    # If the condition is true, print the index of the first occurrence of the number 1 in the list
    print("The first number with remainder 1 is:", list.index(1) + 1)
else:
    # If the condition is false, print the index of the first occurrence of the number 0 in the list
    print("The first number with remainder 0 is:", list.index(0) + 1)
