
n = int(input())  # Take an integer input for the number of elements
l = list(map(int, input().split()))  # Take a list of integers as input
l.sort()  # Sort the list of integers

# Check if there exists any integer i in the list such that i + 1 and i + 2 are also in the list
for i in l:
    if i + 1 in l and i + 2 in l:  # Check if i + 1 and i + 2 are in the list
        print('YES')  # If found, print 'YES' and break the loop
        break
else:
    print('NO')  # If no such integer is found, print 'NO'
