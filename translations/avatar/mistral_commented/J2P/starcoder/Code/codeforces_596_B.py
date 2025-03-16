
# <START-OF-CODE>

# Read the first integer `n` from the standard input stream and assign it to the variable `n`
n = int ( input ( ) )

# Create a new long array `arr` of size `n`
arr = [ ]

# Use a for loop to read `n` integers from the standard input stream and assign them to the corresponding elements of the array `arr`
for i in range ( n ) :
    arr.append ( int ( input ( ) ) )

# Initialize the variable `answer` with the absolute value of the first element of the array `arr`
answer = abs ( arr [ 0 ] )

# Use a for loop to iterate over the remaining elements of the array `arr` and calculate the absolute difference between each element and the previous one, adding the result to the variable `answer`
for i in range ( 1, n ) :
    answer += abs ( arr [ i ] - arr [ i - 1 ] )

# Print the value of the variable `answer` to the standard output stream
print ( answer )

# 