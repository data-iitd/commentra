
# Declare variables
n = 0                       # Number of elements in the array
sq = [0]*10000              # Square array to store squares of numbers from 1 to n-1
fr = [0]*5000               # Frequency array to store the frequency of each difference between squares
com = []                    # Vector to store unique squares
tmp = 0                     # Temporary variable

# Start of the infinite loop
while(1):
  n = int(raw_input())      # Read the number of elements in the array from the user
  if(n==0):break             # If the number is zero, break the loop

  # Initialize square array
  for i in range(1,n):sq[i] = (i*i)%n
  com = []                  # Clear the vector before filling it with new unique squares

  # Find unique squares and store them in the vector
  for i in range(1,n):
    f = True                 # Flag to check if the square is already present in the vector
    for j in range(len(com)):
      if(com[j]==sq[i]):     # If the square is already present, set the flag to false
	f = False
	break
    if(f):com.append(sq[i]) # If the square is not present, add it to the vector

  # Initialize frequency array
  for i in range(0,(n-1)/2):fr[i] = 0

  # Find the frequency of each difference between unique squares
  for i in range(len(com)):
    for j in range(len(com)):
      if(i!=j):               # If the indices are not same
	tmp = com[i]-com[j]    # Calculate the difference between two squares
	if(tmp<0):tmp+=n       # If the difference is negative, make it positive by adding n
	if(tmp>(n-1)/2):tmp = n - tmp # If the difference is greater than half the size of the array, make it smaller by subtracting the difference from the size of the array
	fr[tmp] += 1           # Increment the frequency of the difference

  # Print the frequency of each difference
  for i in range(1,(n-1)/2):print fr[i]

# 