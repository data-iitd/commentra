

K, X = map(int, input().split()) # Read two integers from the standard input and store them in variables K and X

for i in range(X-K+1, X+K): # Start of the for loop
  print(i, end=" ") # Print the current value of i to the standard output

print() # Print a newline character to move the cursor to the next line

