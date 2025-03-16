

import sys ;  # Importing the sys module

def main ( ) :
    n = int ( input ( ) ) ;  # Reading the first integer n from the standard input
    m = int ( input ( ) ) ;  # Reading the second integer m from the standard input
    q = int ( input ( ) ) ;  # Reading the third integer q from the standard input

    a = [ ] ;  # Declaring and initializing an empty list a
    b = [ ] ;  # Declaring and initializing an empty list b
    c = [ ] ;  # Declaring and initializing an empty list c
    d = [ ] ;  # Declaring and initializing an empty list d

    for i in range ( q ) :  # A for loop that reads q integers from the standard input and stores them in lists a, b, c, and d
        a.append ( int ( input ( ) ) - 1 ) ;  # Reading the integer a[i] from the standard input and storing it in the list a after subtracting 1 from it
        b.append ( int ( input ( ) ) - 1 ) ;  # Reading the integer b[i] from the standard input and storing it in the list b after subtracting 1 from it
        c.append ( int ( input ( ) ) ) ;  # Reading the integer c[i] from the standard input and storing it in the list c
        d.append ( int ( input ( ) ) ) ;  # Reading the integer d[i] from the standard input and storing it in the list d

    dfs ( [ ] ) ;  # Calling the recursive function dfs with an empty list as an argument

def dfs ( list ) :  # A recursive function named dfs that takes a list named list as an argument
    if ( len ( list ) == n ) :  # A conditional statement that checks if the length of the list list is equal to the integer n
        score = 0 ;  # Declaring and initializing an integer variable score to zero

        for i in range ( q ) :  # A for loop that calculates the score based on the condition that (list[b[i]] - list[a[i]] == c[i])
            score += ( list [ b [ i ] ] - list [ a [ i ] ] == c [ i ] ) * d [ i ] ;

        global ans ;  # Accessing the global variable ans
        ans = max ( ans, score ) ;  # Updating the value of the global variable ans with the maximum value of ans and the score calculated in the for loop
        return ;  # Returning from the function after updating the value of ans

    if ( len ( list )!= 0 ) :  # A conditional statement that checks if the length of the list list is not zero
        for num in range ( list [ - 1 ], m + 1 ) :  # A for loop that adds the integer num to the list list and recursively calls the function dfs
            list.append ( num ) ;
            dfs ( list ) ;
            list.pop ( ) ;
    else :  # If the length of the list list is zero
        for num in range ( 1, m + 1 ) :  # A for loop that adds the integer num to the list list and recursively calls the function dfs
            list.append ( num ) ;
            dfs ( list ) ;
            list.pop ( ) ;

ans = - 1000000000000000000 ;  # Declaring and initializing a long variable ans to a very large negative number
main ( ) ;  # Calling the main function
print ( ans ) ;  # Printing the value of the global variable ans to the standard output
