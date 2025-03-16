import sys ; // Importing the sys module

sc = sys.stdin ; // Creating a new Scanner object named sc to read input from the standard input
n = int ( sc.readline ( ) ) ; // Reading the first integer value from the standard input and assigning it to the variable n
b = int ( sc.readline ( ) ) ; // Reading the second integer value from the standard input and assigning it to the variable b
ans = [ ] ; // Creating an empty list named ans
q = [ ] ; // Creating an empty list named q

for i in range ( n ) : // Starting a for loop that iterates from 0 to n-1
    t, d = map ( int, sc.readline ( ).split ( ) ) ; // Reading the current test case's first and second integer values and assigning them to the variables t and d

    while q and q [ 0 ] <= t : q.pop ( 0 ) ; // Removing the smallest element from the queue if it is less than or equal to the current test case's first integer value t

    if len ( q ) <= b : # The following if statement checks whether the size of the queue is less than or equal to the value of the variable b
        ans.append ( q [ - 1 ] if q else t ) ; # If the condition is true, then the answer for the current test case is the sum of the last element in the queue and the difference d
        q.append ( ans [ - 1 ] + d ) ; # Adding the answer to the queue
    else :
        ans.append ( - 1 ) ; # If the condition is false, then the answer for the current test case is -1

print ( " ".join ( map ( str, ans ) ) ) ; # The following for loop is used to print the answers for all the test cases

