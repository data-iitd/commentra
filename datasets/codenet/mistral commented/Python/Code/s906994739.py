
n = int(input())  # Read the number of tuples (F and P)
F = [tuple(map(int, input().split())) for _ in range(n)]  # Read n tuples F and convert them to tuples of integers
P = [tuple(map(int, input().split())) for _ in range(n)]  # Read n tuples P and convert them to tuples of integers
ans = -10 ** 18  # Initialize answer with a large negative number

# Loop through all possible combinations of opening time slots
for i in range(1, 2 ** 10):
  tmp = 0  # Initialize temporary variable to store the total profit
  lst = [0] * n  # Initialize list lst of size n to store the profit for each time slot

  # For each time slot j, if i has the j-th bit set to 1, then open the time slot
  for j in range(10):
    if (i >> j) & 1:  # Check if the j-th bit of i is set to 1
      for k in range(n):
        lst[k] += F[k][j]  # Add the profit from F[k][j] to the corresponding position in lst

  # Calculate the total profit for this combination of open time slots
  for k in range(n):
    tmp += P[k][lst[k]]  # Add the profit from P[k][lst[k]] to the temporary variable

  # Update the answer if the current combination results in a larger profit
  ans = max(ans, tmp)

# Print the maximum profit
print(ans)