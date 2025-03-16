
n = int(input())  # Read the number of strings to be processed
arr = {}  # Initialize an empty dictionary to store string frequencies

# Loop through each string input and update its frequency in the dictionary
for i in range(n):
    s = input()  # Read the next string input
    if not s in arr:  # Check if the string is not already in the dictionary
        arr[s] = 1  # Initialize the frequency count to 1
    else:
        arr[s] += 1  # Increment the frequency count by 1

# Find the maximum frequency of any string in the dictionary
max_count = max(arr.values())

# Create a list `dic` containing the first character of each string with the maximum frequency
dic = [key[0] for key in arr.items() if key[1] == max_count]

# Sort the list `dic` to ensure the output is in alphabetical order
out_sort = sorted(dic)

# Print each character in the sorted list `out_sort`
for i in out_sort:
    print(i)

