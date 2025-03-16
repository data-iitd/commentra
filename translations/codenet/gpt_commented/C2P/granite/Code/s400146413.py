
# Python code to perform linear search on an array

# Function to perform linear search on an array
def linearsearch(S, n, key):
  i = 0 # Initialize index for searching
  count = 0 # Initialize count to track if the key is found

  # Loop until the key is found or the end of the array is reached
  while( S[i]!= key ):
    i += 1 # Move to the next index
    # If the index exceeds the size of the array, the key is not found
    if( i >= n  ):
      count = 1 # Set count to indicate the key was not found
      return count # Return count
  return count # Return count (0 if key is found)

# Main function
def main():
  n = int(input("Enter the number of elements in the first array: ")) # Read the number of elements in the first array
  S = list(map(int, input("Enter the elements of the first array (separated by spaces): ").split())) # Read the elements into the first array S
  q = int(input("Enter the number of queries: ")) # Read the number of queries
  T = list(map(int, input("Enter the elements of the second array (separated by spaces): ").split())) # Read the elements into the second array T (the keys to search for)

  count = 0 # Initialize count for missing keys
  key = 0 # Initialize key for searching

  # Loop through each key in T to check if it exists in S
  for j in range(q):
    key = T[j] # Get the current key to search
    # If the key is not found in S, increment the count
    if(linearsearch(S, n, key) == 0):
      count += 1 # Increment count for each missing key

  # Print the total count of keys that were not found in S
  print(count) # Print the total count of keys that were not found in S

# Call the main function
if __name__ == "__main__":
  main()

