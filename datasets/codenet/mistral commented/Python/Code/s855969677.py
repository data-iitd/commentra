# Take an input string 's' from the user
s = input()

# Check if the string 's' is equal to 'RRR'
if s == 'RRR':
  # If it is, print the number 3
  print(3)

# If the string 's' is not equal to 'RRR', check if it is equal to 'SSS'
elif s == 'SSS':
  # If it is, print the number 0
  print(0)

# If the string 's' is not equal to 'RRR' or 'SSS', check if it is equal to either 'RRS' or 'SRR'
elif s == 'RRS' or s == 'SRR':
  # If it is, print the number 2
  print(2)

# If none of the above conditions are met, print the number 1
else:
  # Print the number 1
  print(1)