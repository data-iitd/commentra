# Read an integer input which represents the number of elements in the list
n = int(input())

# Read a line of input, split it into individual string elements, convert them to integers, and store them in a list
l = list(map(int, input().split()))

# Sort the list in ascending order
l.sort()

# Iterate through each element in the sorted list
for i in l:
    # Check if both i + 1 and i + 2 exist in the list
    if i + 1 in l and i + 2 in l:
        # If the condition is met, print 'YES' and exit the loop
        print('YES')
        break
else:
    # If the loop completes without finding the condition, print 'NO'
    print('NO')
