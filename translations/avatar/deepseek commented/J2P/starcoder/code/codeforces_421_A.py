
import java.math.BigInteger ; 
import java.nio.charset.IllegalCharsetNameException ; 
import java.util.* ; 

def main ( ): 
    # Step 3: Create a Scanner object to read input from the user
    sc = Scanner ( System.in ) ; 
    
    # Step 4: Read the values of n, a, and b
    n = sc.nextInt ( ) 
    a = sc.nextInt ( ) 
    b = sc.nextInt ( ) 
    
    # Step 5: Create two ArrayList objects to store the lists of integers
    list1 = ArrayList < Integer > ( ) 
    list2 = ArrayList < Integer > ( ) 
    
    # Step 6: Read the elements of list1 and list2 from the user
    for i in range ( a ) : 
        list1.add ( sc.nextInt ( ) ) 
    for i in range ( b ) : 
        list2.add ( sc.nextInt ( ) ) 
    
    # Step 7: Iterate through the range from 1 to n and print the appropriate list number
    for i in range ( n ) : 
        if ( list1.contains ( i + 1 ) ) : 
            print ( 1, end = " " ) 
        else : 
            print ( 2, end = " " ) 

# 