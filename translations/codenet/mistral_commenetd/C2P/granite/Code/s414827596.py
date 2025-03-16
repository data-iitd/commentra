

import sys # Importing the standard input/output library

while True: # Starting an infinite loop
	try: # Trying to read input from the standard input
		a,b,c,d,e,f = map(int,input().split()) # Reading input as integers and splitting them into variables a to f
	except EOFError: # If end of file is reached
		break # Exiting the loop
	y = (c*d-f*a)/(b*d-e*a) # Calculating the value of y using the given formula
	x = (c*e-f*b)/(a*e-d*b) # Calculating the value of x using the given formula
	if y <= 0.0005: # Checking if y is less than or equal to a very small positive number
		y = 0 # If so, set y to 0
	if x <= 0.0005: # Checking if x is less than or equal to a very small positive number
		x = 0 # If so, set x to 0
	print("%.3f %.3f"%(x,y)) # Printing the values of x and y to the standard output with three decimal places

