
N=int(input())
A=list(map(int,input().split()))
# Read the integer N and the list of integers A from input

s=A[0]^A[1]
# Initialize s with the XOR of the first two elements of A

for i in range(2,N):
    s=s^A[i]
# Update s by XORing it with each subsequent element in A

B=[0]*N
# Create a new list B initialized with zeros, same length as A

for i in range(N):
    B[i]=s^A[i]
# For each element in A, compute the XOR with s and store in B

L=[str(a) for a in B]
# Convert each element in B to a string

L=" ".join(L)
# Join the string elements of L with spaces

print(L)
# Print the final formatted string

