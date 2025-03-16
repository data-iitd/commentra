
# Function to print the first n-1 elements of an array
def white(n,A):
	i=0
	# Loop to print the first n-1 elements of the array
	while(i<n-1):
		print(A[i],end=" ")
		i+=1
	# Print the last element of the array
	print(A[i])

# Function to implement insertion sort algorithm
def insertionsort(n,A):
	i=0
	# Loop to sort the array using insertion sort algorithm
	while(i<n):
		j=0
		# Inner loop to find the position of the current element in sorted array
		while(j<i):
			# Swap if current element is smaller than the previous one
			if(A[i]<A[j]):
				# Swap the elements
				A[i],A[j]=A[j],A[i]
			j+=1
		# Call the white function to print the sorted array after each iteration
		white(n,A)
		i+=1

# Main function to take input and call the insertion sort function
n=int(input())
A=[]
for i in range(n):
	A.append(int(input()))
insertionsort(n,A)

# 