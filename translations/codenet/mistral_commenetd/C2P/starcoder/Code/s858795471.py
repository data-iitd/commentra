
# Function to search for a key in an array
def search(A,n,key):
    i=0
    # Add the key to the end of the array
    A[n]=key
    # Search for the key in the array using a while loop
    while(A[i]!=key) i+=1
    # Return 1 if the key was found before the end of the array, otherwise return 0
    return i!=n

n=int(input())
A=[int(x) for x in input().split()]
q=int(input())
sum=0
for i in range(q):
    key=int(input())
    # Call the search function to find the key in the array
    if(search(A,n,key)): sum+=1
print(sum)

