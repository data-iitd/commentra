
import math 
import sys 

n = int ( input ( ) ) 
str = input ( ) 
l = list ( str ) 
t = 0 
x = 0 
y = 0 

# Check each character in the character array
for i in range ( n ) : 
    if l [ i ] != '4' and l [ i ] != '7' : 
        t = 1 

# If t is 1, print "NO"
if t == 1 : 
    print ( "NO" ) 
else : 
    # Calculate the sum of the first half of the character array
    for i in range ( n / 2 ) : 
        x = x + int ( l [ i ] ) 
    # Calculate the sum of the second half of the character array
    for i in range ( n - 1 , ( n / 2 ) - 1 , - 1 ) : 
        y = y + int ( l [ i ] ) 
    # If x equals y, print "YES", otherwise print "NO"
    if x == y : 
        print ( "YES" ) 
    else : 
        print ( "NO" ) 

# 