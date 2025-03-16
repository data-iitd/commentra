# Get the number of strings to be processed from the user
n = int(input())

# Initialize an empty dictionary to store the count of each unique string
arr = {}

# Iterate through each string in the input
for i in range(n):
    # Get the next string from the user input
    s = input()
    
    # If the string is not already in the dictionary, add it with a count of 1
    if not s in arr:
        arr[s] = 1
    # If the string is already in the dictionary, increment its count by 1
    else:
        arr[s] += 1

# Find the maximum count of any string in the dictionary
max_count = max(arr.values())

# Find all strings with the maximum count
dic = [key for key in arr.items() if key[1] == max_count]

# Sort the list of strings with maximum count in ascending order
out_sort = sorted(dic, key=lambda x: x[0])

# Print each string with the maximum count in the order of their appearance in the input
for i in out_sort:
    print(i[0])
