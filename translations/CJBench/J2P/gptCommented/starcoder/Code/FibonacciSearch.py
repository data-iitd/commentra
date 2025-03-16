
# <START-OF-CODE>

# Create a Scanner object to read input from the user
scanner = Scanner(sys.stdin)

# Read the size of the array from user input
n = scanner.nextInt()

# Initialize an array of Integer with the specified size
array = [0] * n

# Populate the array with user input values
for i in range(n):
    array[i] = scanner.nextInt()

# Read the key value to search for in the array
key = scanner.nextInt()

# Create an instance of Main to access the find method
searcher = Main()

# Call the find method to search for the key in the array and store the result index
index = searcher.find(array, key)

# Print the index of the found key or -1 if not found
print(index)

# Close the scanner to prevent resource leaks
scanner.close()

# 