

n = int(input()) # Reading the number of elements in the array from user input
a = list(map(int, input().split())) # Creating a list of integers from user input

# Sorting the list in ascending order
a.sort()

# Checking if there is any pair of adjacent elements that satisfy the condition
for i in range(len(a) - 1):
  # Checking if the next element is less than twice the current element and they are not the same
  if a[i + 1] < a[i] * 2 and a[i]!= a[i + 1]:
    print("YES") # Printing "YES" if a pair is found
    break # Exiting the loop if a pair is found
else:
  print("NO") # If no pair is found, printing "NO"

