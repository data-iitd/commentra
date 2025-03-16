
n = int(input()) # Read the number of elements in the list
l1 = list(map(int, input().split())) # Read the list elements and convert them to integers
l1.sort() # Sort the list in ascending order

a = l1[-1] # Assign the last element of the sorted list to the variable a
b = l1[0] # Assign the first element of the sorted list to the variable b

if a == b: # Check if the first and the last elements are equal
    print(a - b, (n * (n - 1)) // 2) # If so, calculate and print the result
else:
    ac = l1.count(a) # Count the number of occurrences of the element a in the list
    bc = l1.count(b) # Count the number of occurrences of the element b in the list
    print(a - b, ac * bc) # Print the result