
n = int(input()) # Read an integer value from the standard input and store it in 'n'
a = [int(input()) for _ in range(n)] # Read 'n' integer values from the standard input and store them in the list 'a'

t = 0 # Initialize the variable 't' to zero

for i in range(n): # Iterate through each element of the list 'a'
    s = 0 # Initialize the variable's' to zero for summation

    for j in range(i+1, n): # Iterate through all other elements of the list 'a' except the current element 'i'
        m = a[i] * a[j] # Multiply the current element 'a[i]' with the next element 'a[j]' and store the result in'm'
        s += m # Add the product'm' to the sum's'

    t += s # Add the sum's' to the total sum 't'

print(t) # Print the total sum 't' to the standard output

