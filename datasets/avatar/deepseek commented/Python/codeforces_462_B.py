
n , k = map ( int , input ( ).split ( ) )
# Read the values of n and k from input

s = input ( )
# Read the string s from input

count = [ 0 ] * 26
# Initialize a list `count` with 26 zeros to count occurrences of each letter

for c in s :
    count [ ord ( c ) - ord ( "A" ) ] += 1
# Iterate over each character in the string `s`, calculate its index in the `count` list, and increment the corresponding count

count.sort ( reverse = True )
# Sort the `count` list in descending order

res = 0
# Initialize `res` to 0, which will be used to store the result

for i in range ( 26 ) :
    if count [ i ] >= k :
        res += k * k
        print ( res )
        exit ( )
    # If the current count is greater than or equal to `k`, calculate the result using the formula `k * k` and print it, then exit the program

    k -= count [ i ]
    res += count [ i ] ** 2
# If the current count is less than `k`, subtract the current count from `k` and add the square of the current count to `res`

print ( res )
# Print the final result `res`

