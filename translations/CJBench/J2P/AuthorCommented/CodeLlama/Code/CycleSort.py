
# Read the size of the array
n = int(input())

# Read the array elements
array = [int(input()) for i in range(n)]

# Sort the array
sorter = Main()
sorter.sort(array)

# Print the sorted array
for num in array:
    print(num, end=" ")

# END-OF-CODE
