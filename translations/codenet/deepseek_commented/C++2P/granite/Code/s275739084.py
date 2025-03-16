
A,B = map(int,input().split()) # Take input from the user for variables A and B.
C = A + B # Calculate the sum of A and B and store it in variable C.
if A%3!=0 and B%3!=0 and C%3!=0: # Check if neither A, B, nor the sum C is divisible by 3.
    print("Impossible") # If the condition is true, print "Impossible" to the console.
else:
    print("Possible") # Otherwise, print "Possible" to the console.

