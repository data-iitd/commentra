
# Python code to perform insertion sort

# Function to print the array elements
def white(n, A):
    for i in range(n - 1):
        print(A[i], end=" ")
    print(A[i])

# Function to perform insertion sort on the array
def insertionsort(n, A):
    for i in range(n):
        for j in range(i):
            if A[i] < A[j]:
                A[i], A[j] = A[j], A[i] # Swap the elements
        white(n, A)

# Main function to read input and call the insertion sort function
def main():
    n = int(input("Enter the number of elements: ")) # Read the number of elements from user input
    A = [int(x) for x in input("Enter the elements of the array: ").split()] # Read the elements of the array from user input
    insertionsort(n, A) # Call the insertion sort function to sort the array

if __name__ == "__main__":
    main() # Call the main function to execute the code

