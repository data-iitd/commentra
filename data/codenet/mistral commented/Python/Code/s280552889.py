# Ask the user to input an integer value
N = int(input())

# Check if the number is even or odd
if N % 2 == 0:
  # If the number is even, print the result of dividing it by 2
  print(N // 2)
else:
  # If the number is odd, print the result of dividing it by 2 and adding 1
  print(N // 2 + 1)