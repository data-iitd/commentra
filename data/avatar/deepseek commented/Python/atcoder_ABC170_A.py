
a = list(map(int, input().split()))  # Take input from user, split it into a list of integers
for e, i in enumerate(a):  # Iterate over the list, checking each element
    if i == 0:  # If an element is 0
        print(e + 1)  # Print the position (1-indexed) of that element and break the loop
        break

