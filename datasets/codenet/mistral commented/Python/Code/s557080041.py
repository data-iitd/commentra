
N = input("Take an integer input from the user: ") # Take an integer input from the user
if N == 0: # Check if the input is zero
  print("Yes") # If yes, print 'Yes'
else:
  N = str(N) # Convert the integer to a string
  L = list(N) # Convert the string to a list of characters
  L = [int(s) for s in L] # Convert each character to an integer
  X = sum(L) # Calculate the sum of all the integers in the list
  if X % 9 == 0: # Check if the sum is divisible by 9
    print("Yes") # If yes, print 'Yes'
  else:
    print("No") # If not, print 'No'