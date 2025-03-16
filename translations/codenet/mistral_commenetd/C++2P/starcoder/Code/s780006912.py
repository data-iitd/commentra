
# Declare the main function
def main():
  n = int(input()) # Take the size of the array as input from the user
  array = [int(x) for x in input().split()] # Read the array elements from the user and store them in the array

  sum = 0 # Initialize the sum variable to zero

  # Calculate the sum of all the products of distinct pairs of elements in the array
  for i in range(n-1): # Outer loop runs from 0 to n-2
    for j in range(i+1,n): # Inner loop runs from i+1 to n
      sum += array[i]*array[j] # Add the product of current and next element to the sum

  print(sum) # Print the sum of all the products of distinct pairs of elements in the array

# Check if this program runs correctly
if __name__ == "__main__":
  main()

