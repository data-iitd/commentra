

n = int(input("Enter the number of elements: ")) # Read the number of elements from the standard input and store it in n

a = [int(input("Enter a number: ")) for _ in range(n)] # Initialize the array a with input numbers

count = [0] * n # Initialize an array of size n to store the count of occurrences of each number

for i in range(n): # Iterate through the array a and increment the corresponding element in the count array
  count[a[i]-1] += 1

print("Printing the contents of the count array:")
for i in range(n): # Print the contents of the count array to the standard output
  print(count[i])

print("Program completed successfully.")

