# Read an integer input from the user
n = int(input())

# Read a line of space-separated integers, convert them to a list of integers
x = list(map(int, input().split()))

# Reverse the list of integers
x.reverse()

# Print the reversed list, unpacking the list to print each element separated by a space
print(*x)
