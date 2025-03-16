
n , m = map ( int , input ( ).split ( ) )  # Read two integers n and m from input
l = list ( map ( int , input ( ).split ( ) ) )  # Read a list of integers
l2 = [ ]  # Initialize an empty list to store the results

# Iterate over each element in the list l
for i in l :
    if i % m == 0 :  # Check if the element is divisible by m
        l2.append ( i // m )  # Append the quotient to l2
    else :
        l2.append ( i // m + 1 )  # Append the quotient plus one to l2

mx = max ( l2 )  # Find the maximum value in l2

# Iterate over l2 to find the index of the maximum value
for i in range ( n ) :
    if l2 [ i ] == mx :
        ind = i  # Store the index of the maximum value

print ( ind + 1 )  # Print the index of the maximum value plus one

