# Step 1: Read input strings
a=input(); n=len(a)
b=input(); m=len(b)

# Step 2: Define variables for string lengths and minimum differences
ans=M+10

# Step 3: Calculate the minimum number of differences
for i in range(1,n-m+1):
    sum=0
    for j in range(1,m+1):
        if a[i+j-1]!=b[j]:
            sum+=1
    ans=min(ans,sum)

# Step 4: Output the result
print(ans)

