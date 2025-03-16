import sys

n = int(sys.stdin.readline())
list = []

# Reading the elements and adding them to the list
for i in range(n):
    list.append(int(sys.stdin.readline()))

list.sort()

c = 1

# Iterating through the sorted list to find the smallest missing positive integer
for i in range(n):
    if list[i] >= c:
        c += 1

print(c)

# Debug method for debugging purposes
def debug(*obj):
    print(obj)

