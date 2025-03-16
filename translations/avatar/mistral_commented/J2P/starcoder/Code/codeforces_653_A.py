
import sys # Import the sys package for reading input from the console

# Read the number of elements in the list from the user input
n = int(sys.stdin.readline())

# Create an empty list to store the unique and sorted list elements
a = []
for i in range(n): # Iterate through the input elements
  value = int(sys.stdin.readline()) # Read the next input value
  a.append(value) # Add the value to the list

# Filter and sort the list using Python list comprehension
a = sorted(list(set(a))) # Sort the list and remove duplicates

# Check if there exists a sequence of three consecutive elements with a difference of 1
found = False
for i in range(len(a)): # Iterate through the list elements
  if i + 1 < len(a) and i + 2 < len(a): # Check if the next and next-next elements exist
    if a[i] + 1 == a[i + 1] and a[i + 1] + 1 == a[i + 2]: # Check if the difference is 1
      found = True # Set the found flag if a sequence is found
      break # Exit the loop if a sequence is found

# Write the output to the console
print("YES" if found else "NO")

