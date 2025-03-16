# <START-OF-CODE>

# Function to check if a weight can be carried by a knapsack of capacity 'wei'
def check(n, wei, book):
  tmp = wei # Initialize temporary variable 'tmp' to 'wei'
  n -= 1 # Decrement 'n' (number of items left to be put in the knapsack)

  # Loop through all the items in the vector 'book'
  for i in range(len(book)):
    # If the weight of the current item is greater than the remaining capacity,
    # check if there is still room for more items by decrementing 'n' and resetting 'tmp' to 'wei'
    if tmp < book[i]:
      if n > 0: # If there are still items left to be put in the knapsack
        n -= 1 # Decrement 'n'
        tmp = wei # Reset 'tmp' to 'wei'
        # Check if the current weight is less than the weight of the current item
        if tmp < book[i]:
          return False
      else: # If there are no more items left to be put in the knapsack
        return False

    # Subtract the weight of the current item from the remaining capacity
    tmp -= book[i]

  # If all items have been considered and the remaining capacity is still greater than zero,
  # then the given weight can be carried by the knapsack
  return True

# Loop through the input until the end of the file is reached
while True:
  m, n = map(int, input().split()) #'m' is the maximum weight the knapsack can carry and 'n' is the number of items

  if m == 0:
    break

  book = [] # Initialize an empty vector 'book' to store the weights of the items

  # Loop through all the items and add their weights to the vector 'book'
  for i in range(n):
    tmp = int(input())
    book.append(tmp)

  # Use binary search to find the maximum weight that can be carried by the knapsack
  l = 0
  r = 1500000
  ans = 0
  while l < r:
    # Calculate the middle value of the range [l, r]
    mid = (l + r) // 2

    # If the middle value can be carried by the knapsack, update 'ans' and shrink the range to [l, mid]
    if check(m, mid, book):
      ans = mid
      r = mid
    # If the middle value cannot be carried by the knapsack, shrink the range to [mid+1, r]
    else:
      l = mid + 1

  # Output the maximum weight that can be carried by the knapsack
  print(ans)

# 