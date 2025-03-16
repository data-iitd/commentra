
n,k=map(int,input().split())  # 1. Taking input for length of string and number of queries
a=[i for i in input()]  # 2. Taking input for the string and converting it to a list of characters
c=[0]*n  # 3. Initializing a list of zeros with the same length as the string

# 4. Iterating over the range from 1 to n-1 to count "AC" pairs
for i in range(1,n):
    if a[i]=="C" and a[i-1]=="A":
        c[i]=c[i-1]+1  # Incrementing the count if "C" is followed by "A"
    else:
        c[i]=c[i-1]  # Otherwise, carry over the previous count

# 5. Iterating over the range k to process each query
for w in range(k):
    l,r=map(int,input().split())  # Taking input for the left and right indices of the query
    print(c[r-1]-c[l-1])  # Printing the difference to get the number of "AC" pairs in the subsegment

