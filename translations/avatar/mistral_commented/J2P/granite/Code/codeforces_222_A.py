
n = int(input()) # Reading the first integer from the input and assigning it to variable n
k = int(input()) # Reading the second integer from the input and assigning it to variable k
l = 0 # Initializing the variable l with value 0
c = 1 # Initializing the variable c with value 1

for i in range(n): # Starting a for loop that iterates n times
    a = int(input()) # Reading the next integer from the input and assigning it to variable a

    if a == l: # If the current integer is equal to the previous one
        c += 1 # Increment the counter c by 1
    else:
        c = 1 # Otherwise, reset the counter c to 1

    l = a # Assigning the current integer to the previous integer variable l

if c + k > n: # Checking if the sum of counter c and integer k is greater than the total number of integers n
    print(n - c) # If true, print the difference between n and c
else:
    print(-1) # If false, print -1

