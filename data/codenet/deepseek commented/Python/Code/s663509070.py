
N,D=map(int,input().split())  # Read the number of vectors N and the dimension D
mat=[]  # Initialize an empty list to store the vectors
for d in range(N):  # Loop to read each vector
     mat.append([int(x) for x in input().split()])  # Append each vector as a list of integers to mat

import math  # Import the math module to use the sqrt function
c=0  # Initialize a counter to count the number of pairs with integer distance
for i in range(len(mat)-1):  # Loop to iterate over the vectors
    for j in range(i+1,len(mat)):  # Nested loop to iterate over pairs of vectors
        dist=math.sqrt(sum([(x-y)**2 for x,y in zip(mat[i],mat[j])]))  # Calculate the Euclidean distance between the vectors
        if int(dist)==dist:  # Check if the distance is an integer
                c+=1  # Increment the counter if the distance is an integer
print(c)  # Print the final count of pairs with integer distance

