# Include the standard input output header file

n,k = map(int,input().split()) # Read two integers n and k from the standard input using the split function

if(k%2==0): # Check if k is even
    l=0 # Initialize the variable l to zero
    r=0 # Initialize the variable r to zero
    for i in range(1,n+1): # Iterate through the numbers from 1 to n
        if(i%k==k/2): # Check if the remainder of i divided by k is equal to k/2
            l+=1 # If it is, increment the variable l by 1
        elif(i%k==0): # Else if the remainder of i divided by k is equal to 0
            r+=1 # Increment the variable r by 1
    print(l*l*l+r*r*r) # Calculate and print the result using the expressions l*l*l+r*r*r
else: # Else if k is odd
    r=0 # Initialize the variable r to zero
    for i in range(1,n+1): # Iterate through the numbers from 1 to n
        if(i%k==0): # Check if the remainder of i divided by k is equal to 0
            r+=1 # If it is, increment the variable r by 1
    print(r*r*r) # Calculate and print the result using the expression r*r*r

