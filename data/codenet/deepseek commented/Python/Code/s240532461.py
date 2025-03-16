
N,L= map(int,input().split())
# Read the values of N and L

aji = []
# Initialize an empty list to store the values

for i in range(1,N+1):
    aji.append(L+i-1)
# Append values to the list `aji` from L+1 to L+N

if min(aji) >= 0:
    aji.pop(aji.index(min(aji)))
# If the minimum value in `aji` is greater than or equal to 0, remove it
elif max(aji) <=0:
    aji.pop(aji.index(max(aji)))
# If the maximum value in `aji` is less than or equal to 0, remove it
else:
    aji.pop(aji.index(min(aji,key=abs)))
# If neither condition is true, remove the value with the smallest absolute value

print(sum(aji))
# Print the sum of the remaining values in `aji`

