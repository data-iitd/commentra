
# Take an integer input from the user and assign it to the variable n
n = int(input())

# Take a string input from the user, split it into a list of strings,
# apply the int() function to each string in the list using map(),
# and assign the resulting list of integers to the variable x
x = list(map(int, input().split()))

# Reverse the order of the elements in the list x
x.reverse()

# Print each element of the list x separated by spaces
print(*x)