
import sys ; // Importing the sys module

n = int ( sys.stdin.readline ( ) ) ; // Reading the first integer n from the standard input
m = int ( sys.stdin.readline ( ) ) ; // Reading the second integer m from the standard input

q1 = [ ] ; // Creating an empty queue q1
q2 = [ ] ; // Creating an empty queue q2

for i in range ( 1, n + 1 ) : // Iterating through the input values from 1 to n
    q1.append ( int ( sys.stdin.readline ( ) ) ) ; // Adding the next integer value to the queue q1
    q2.append ( i ) ; // Adding the current index value to the queue q2

ans = 0 ; // Initializing the answer variable to 0
while ( len ( q1 ) > 0 ) : // Starting the while loop to process the queues until both are empty
    if ( q1 [ 0 ] <= m ) : // Checking if the next value in q1 is less than or equal to m
        q1.pop ( 0 ) ; // Removing the next value from q1
        ans = q2.pop ( 0 ) ; // Removing the corresponding index value from q2 and assigning it to the answer variable
    elif ( q1 [ 0 ] > m ) : // Checking if the next value in q1 is greater than m
        x = q1.pop ( 0 ) ; // Removing the next value from q1
        val = x - m ; // Calculating the new value by subtracting m from the next value
        q1.append ( val ) ; // Adding the new value back to the queue q1
        val2 = q2.pop ( 0 ) ; // Removing the corresponding index value from q2
        q2.append ( val2 ) ; // Adding the index value back to the queue q2

print ( ans ) ; // Printing the final answer

