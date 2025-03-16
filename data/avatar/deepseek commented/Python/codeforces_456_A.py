
n = int(input())  # Take an integer input representing the number of elements in the list `m`
m = [[int(x) for x in input().split()] for i in range(n)]  # Create a list of lists `m` where each sublist contains two integers
m.sort(reverse=True)  # Sort the list `m` in descending order based on the second element of each sublist
a = m[0]  # Assign the first element of the sorted list `m` to the variable `a`

# Iterate over the rest of the elements in `m` starting from the second element
for i in m[1:]:
    if i[1] > a[1]:  # Check if the second element of the current element `i` is greater than the second element of the variable `a`
        print('Happy Alex')  # If true, print "Happy Alex" and break out of the loop
        break
    a = i  # If false, assign the current element `i` to the variable `a`
else:  # If the loop completes without breaking
    print('Poor Alex')  # Print "Poor Alex"

