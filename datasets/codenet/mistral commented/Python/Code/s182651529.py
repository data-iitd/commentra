
# Define variables N and K by taking their integer values from user input
N, K = map(int, input().split())

# Initialize an empty list to store the integer scores provided by the user
score = []

# Initialize MAE (Mean Absolute Error) and USIRO (Under Sample Index) variables to 0
mae = 0
usiro = K

# Iterate through the indices of the list 'score' from 'i' starting from 0 up to N-K
for i in range(N-K):

  # Check if the score at the index 'mae' is less than the score at the index 'usiro'
  if score[mae] < score[usiro]:

    # If the condition is true, print 'Yes'
    print('Yes')

  # If the condition is false, print 'No'
  else:
    print('No')

  # After printing the result, increment both 'mae' and 'usiro' by 1
  mae += 1
  usiro += 1
