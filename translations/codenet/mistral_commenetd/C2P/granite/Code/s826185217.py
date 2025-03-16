
a, b, c, d = map(int, input().split()) # Read four integers from the standard input and store them in the variables a, b, c, and d

if a + b > c + d: # Check if the sum of a and b is greater than the sum of c and d
    print("Left") # If true, print "Left" to the standard output
elif a + b < c + d: # Check if the sum of a and b is less than the sum of c and d
    print("Right") # If true, print "Right" to the standard output
else: # If neither of the above conditions is true
    print("Balanced") # Print "Balanced" to the standard output

