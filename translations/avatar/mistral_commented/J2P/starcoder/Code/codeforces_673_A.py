
import sys ; // Importing the sys module

n = int ( sys.stdin.readline ( ) ) ; // Reading the number of elements in the ArrayList from the standard input stream

a = [ ] ; // Creating an empty ArrayList named a

for i in range ( n ) :
    value = int ( sys.stdin.readline ( ) ) ; // Reading an integer value from the standard input stream
    a.append ( value ) ; // Adding the value to the ArrayList

result, pos, flag = 0, 0, 0 ; // Declaring and initializing the variables result, pos, and flag

if a [ 0 ] > 15 :
    result = 15 ;
else :
    for i in range ( 1, n ) :
        if a [ i ] - a [ i - 1 ] > 15 :
            pos = i - 1 ;
            flag = 1 ;
            break ;
    if flag == 1 :
        result = a [ pos ] + 15 ;
    else :
        result = a [ n - 1 ] + 15 ;

if result > 90 : result = 90 ;

print ( result ) ;

