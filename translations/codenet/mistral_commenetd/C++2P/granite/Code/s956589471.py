

a, b, c, d, e, k = map(int, input().split()) # Read the values of these variables from the standard input using input() and split them into a list of strings, then convert each string to an integer using map()

if e - a <= k: # Perform a simple condition check using the relational operator <=
    print("Yay!") # If the condition is true, print "Yay!" to the standard output
else:
    print(":(") # If the condition is false, print ":" and a sad face "(" to the standard output

