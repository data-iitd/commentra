A, B, C = map(int, input().split())  # Assigning three integers to variables A, B, and C using map and input functions

if B < C:  # Check if the second integer, B, is less than the third integer, C
  print(0)  # If the condition is true, print 0
else:
  if A * C < B:  # Check if the product of the first integer, A, and the third integer, C, is less than the second integer, B
    print(C)  # If the condition is true, print the third integer, C
  else:
    print(B//A)  # If the condition is false, print the second integer, B, divided by the first integer, A.