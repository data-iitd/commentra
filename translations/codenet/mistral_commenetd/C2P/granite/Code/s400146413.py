

# Python code to perform linear search on an array

# Function to perform linear search on an array
def linearsearch(S, n, key):
  i = 0 # Initialize index variable i to 0
  count = 0 # Initialize count variable to 0

  # Search for the key in the array S until it is found or the end of the array is reached
  while( S[i]!= key ):
    i += 1 # Increment i by 1 for each iteration
    if( i >= n ): # Check if the end of the array has been reached
      count = 1 # Set count to 1 if key is not found in the array
      return count # Return count to the calling function

  # If key is found, return 0 to indicate that it was found
  return 0

# Main function to read input and call linearsearch function
def main():
  n = int(input("Enter the size of the array S: ")) # Read the size of the array S from the user
  S = [int(input(f"Enter integer S[{i}]: ")) for i in range(n)] # Read the elements of array S from the user
  q = int(input("Enter the number of queries: ")) # Read the number of queries from the user
  T = [int(input(f"Enter integer T[{j}]: ")) for j in range(q)] # Read the elements of array T from the user
  count = 0 # Initialize count variable to 0

  # Call linearsearch function for each element of array T and increment count if key is not found
  for j in range(q):
    key = T[j] # Assign the current element of array T to key variable
    if(linearsearch(S, n, key) == 1): # Call linearsearch function and check if count is 1 (key not found)
      count += 1 # Increment count if key is not found

  # Print the final count to the user
  print(f"Number of integers in array S that are not present in array T: {count}")

# Call the main function to execute the program
if __name__ == "__main__":
  main()

