
n = int(input()) # Read the value of n from the standard input
a = [float(input()) for _ in range(n)] # Read n floating-point numbers from the standard input and store them in a list
while len(a) > 1: # Enter a loop that continues until only one element remains in the list a
    a.sort() # Sort the list a in ascending order
    na = [] # Create an empty list na to store the updated elements
    for i in range(2, len(a)): # Iterate over the list a starting from the third element
        na.append(a[i]) # Append the elements from a to na, excluding the first two
    na.append((a[0]+a[1])/2) # Append the average of the first two elements to na
    a = na # Update the list a with the new list na
print(a[0]) # Print the single remaining element in the list a
