
l , r = [ int ( x ) for x in input ( ).split ( ) ]
# Taking the range as input from the user

curr = r
s = 0
# Initialize curr to r and s to 0

while curr :
    s += 1
    curr //= 10
# Determine the number of digits in r and store it in s

first = 10 ** s
second = first // 2
# Calculate the smallest number with s digits and its half

ans = - 1
# Initialize ans to -1 to store the maximum product found

for i in [ l , r , first , second ] :
    if i >= l and i <= r :
        curr = i
        rev = ''
        for k in str ( curr ) :
            rev += str ( 9 - int ( k ) )
        ans = max ( ans , int ( rev ) * curr )
# Iterate over the specified numbers, check if they are within the range,
# reverse the digits, calculate the product, and update ans if necessary

print ( ans )
# Print the maximum product found

