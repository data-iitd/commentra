
n,m=list(map(int,input().split()))  # Read the number of elements (n) and the number of pairs (m)
a=[]  # Initialize an empty list `a` to store the first elements of each pair
b=[]  # Initialize an empty list `b` to store the second elements of each pair

# Loop to read `m` pairs and store them in lists `a` and `b`
for i in range(m):
    a1,b1=list(map(int,input().split()))  # Read the pair (a1, b1)
    a.append(a1)  # Append `a1` to list `a`
    b.append(b1)  # Append `b1` to list `b`

# Loop to print the sum of counts of each element from 1 to `n` in lists `a` and `b`
for i in range(1,n+1):
    print(a.count(i)+b.count(i))  # Print the sum of counts of `i` in lists `a` and `b`

