

# Python code to implement insertion sort algorithm

# Function to print the first n-1 elements of an array
def white(n,A):
	for i in range(n-1):
		print(A[i],end=" ")
	print(A[i])

# Function to implement insertion sort algorithm
def insertionsort(n,A):
	for i in range(n):
		for j in range(i):
			if A[i]<A[j]:
				a=A[i]
				A[i]=A[j]
				A[j]=a
		white(n,A)

# Main function to take input and call the insertion sort function
def main():
	n=int(input("Enter the size of the array: "))
	A=[int(x) for x in input("Enter the elements of the array: ").split()]
	insertionsort(n,A)

# Call the main function to execute the program
if __name__=="__main__":
	main()

