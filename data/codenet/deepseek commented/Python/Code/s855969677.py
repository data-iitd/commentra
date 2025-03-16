
s=input()  # Taking a string input from the user

if s == 'RRR':  # Checking if the input string is 'RRR'
  print(3)  # If true, print the number 3
elif s == 'SSS':  # Checking if the input string is 'SSS'
  print(0)  # If true, print the number 0
elif s == 'RRS' or s == 'SRR':  # Checking if the input string is 'RRS' or 'SRR'
  print(2)  # If true, print the number 2
else:  # If none of the above conditions are met
  print(1)  # Print the number 1

