
# Input section
n,c = map(int,input().split()) # Read input values for n and c from standard input
x = [0]*(n+1) # Declare and initialize vector x of size n+1 with zero values
v = [0]*(n+1) # Declare and initialize vector v of size n+1 with zero values
for i in range(1,n+1): # Loop through each element in the array
    x[i],v[i] = map(int,input().split()) # Read input values for x[i] and v[i] from standard input

# Calculate left prefix sums
lefttotal = [0]*(n+1) # Declare and initialize vector lefttotal of size n+1 with zero values
maxlefttotal = [0]*(n+1) # Declare and initialize vector maxlefttotal of size n+1 with zero values
for i in range(1,n+1):
    lefttotal[i] = lefttotal[i-1] + v[i] # Calculate prefix sums of vector v
    maxlefttotal[i] = max(maxlefttotal[i-1],lefttotal[i]-x[i]) # Calculate maximum prefix sums excluding current element

# Calculate right prefix sums
righttotal = [0]*(n+1) # Declare and initialize vector righttotal of size n+1 with zero values
maxrighttotal = [0]*(n+1) # Declare and initialize vector maxrighttotal of size n+1 with zero values
for i in range(1,n+1):
    righttotal[i] = righttotal[i-1] + v[n-i+1] # Calculate prefix sums of reversed vector v
    maxrighttotal[i] = max(maxrighttotal[i-1],righttotal[i] -(c - x[n+1-i])) # Calculate maximum prefix sums excluding current element

# Calculate answer
ans = 0
for i in range(1,n+1):
    ans = max(ans,lefttotal[i]-x[i]) # Calculate maximum sum by including current element in left sum
    ans = max(ans,lefttotal[i]-2*x[i]+maxrighttotal[n-i]) # Calculate maximum sum by excluding current element in left sum and including it in right sum
    ans = max(ans,righttotal[i]-(c -x[n+1-i])) # Calculate maximum sum by including current element in right sum
    ans = max(ans,righttotal[i]-2*(c-x[n+1-i])+maxlefttotal[n-i]) # Calculate maximum sum by excluding current element in right sum and including it in left sum

# Output answer
print(ans)

