
# This is the main function where the program starts execution
def main():
 # Declare an integer array 'a' of size 1000 and three integer variables 'n', 'i', and 'j'
 a = [0] * 1000
 n = 0
 i = 0
 j = 0
 d = 0 # Initialize a variable 'd' to keep track of the number of swaps made during sorting

 # Read the size of the array from the user
 n = int(input())

 # Read 'n' integers from the user and store them in the array 'a'
 for i in range(n):
  a[i] = int(input()) # Read an integer and store it in the current index of the array 'a'

 # Implement bubble sort algorithm to sort the array 'a' in ascending order
 for i in range(n): # Iterate through each index of the array 'a'
  for j in range(n-1, i, -1): # Iterate through the array from the last index to the current index
   if a[j] < a[j-1]: # Check if the current element is smaller than the previous element
    a[j], a[j-1] = a[j-1], a[j] # Swap the elements if they are in the wrong order
    d += 1 # Increment the swap counter

 # Print the sorted array 'a'
 print(a[0], end=" ") # Print the first element of the array
 for i in range(1, n): # Iterate through the remaining elements of the array
  print(a[i], end=" ") # Print each element followed by a space
 print() # Print a newline character at the end of the line

 # Print the number of swaps made during sorting
 print(d)

 # Return 0 to indicate successful execution of the program
 return 0

# Call the main function to start the program
if __name__ == "__main__":
 main()

