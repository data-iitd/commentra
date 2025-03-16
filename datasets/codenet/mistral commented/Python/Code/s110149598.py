
a, b = input().split()  # Split the user input into two variables: a and b

if a < b:  # Check if a is less than b
    print("<")  # If true, print "<"
elif a > b:  # Check if a is greater than b
    print(">")  # If true, print ">"
else:  # If neither of the previous conditions are true
    print("=")  # Then a must be equal to b, print "="