
n=int(input())  # Read the number of elements in the list `t`
t=list(map(int,input().split()))  # Read the list of integers and store it in `t`
m=int(input())  # Read the number of queries
for i in range(m):  # Loop through each query
    p,x=map(int,input().split())  # Read the query parameters `p` and `x`
    s=0  # Initialize the sum `s` to 0 for each query
    for j in range(len(t)):  # Iterate over the list `t` to calculate the sum
        if j==p-1:  # Check if the current index `j` is the position `p-1`
            s+=x  # Add `x` to `s` if the condition is true
        else:
            s+=t[j]  # Add the element `t[j]` to `s` otherwise
    print(s)  # Print the final sum `s` for the current query

