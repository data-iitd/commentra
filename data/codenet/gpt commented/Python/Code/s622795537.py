# Read an integer input which represents the number of strings to be processed
n = int(input())

# Initialize an empty dictionary to store the count of each string
arr = {}

# Loop through the range of n to read n strings
for i in range(n):
    s = input()  # Read a string input
    # Check if the string is already in the dictionary
    if not s in arr:
        # If not, add the string to the dictionary with a count of 1
        arr[s] = 1
    else:
        # If it is already present, increment its count by 1
        arr[s] += 1

# Find the maximum count of occurrences among the strings
max_count = max(arr.values())

# Create a list of strings that have the maximum count
dic = [key[0] for key in arr.items() if key[1] == max_count]

# Sort the list of strings with the maximum count in alphabetical order
out_sort = sorted(dic)

# Print each string from the sorted list
for i in out_sort:
    print(i)
