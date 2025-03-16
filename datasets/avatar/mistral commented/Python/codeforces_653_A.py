
n = int(input())  # Read the number of elements in the list
l = list(map(int, input().split()))  # Read the list of integers and convert them to integers
l.sort()  # Sort the list in ascending order

for i in l:  # Iterate through each element in the sorted list
    if i + 1 in l and i + 2 in l:  # Check if the next two elements are also in the list
        print('YES')  # If yes, print 'YES' and break out of the loop
        break
else:
    print('NO')  # If no, print 'NO' after the loop finishes