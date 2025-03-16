
N = input()
# Taking an input from the user and storing it in N
if N == 0:
  # Checking if N is equal to 0
  print('Yes')
else:
  # If N is not 0, proceed with the following steps
  N = str(N)
  # Converting N to a string
  L = list(N)
  # Converting the string to a list of its characters
  L = [int(s) for s in L]
  # Converting each character back to an integer and storing in L
  X = sum(L)
  # Calculating the sum of the digits in L and storing it in X
  if X % 9 == 0:
    # Checking if X is divisible by 9
    print('Yes')
  else:
    # If X is not divisible by 9, print 'No'
    print('No')

