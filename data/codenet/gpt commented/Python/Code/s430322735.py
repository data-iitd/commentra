# Read an integer input which represents the number of strings to be processed
n = int(input())

# Initialize an empty list to store the sorted strings
lst = []

# Initialize a counter for pairs
pair = 0

# Loop through the number of strings specified by n
for i in range(n):
    # Read a string, sort its characters, and join them back into a single string
    st = ''.join(sorted(list(input())))
    # Append the sorted string to the list
    lst.append(st)

# Sort the list of sorted strings
lst = sorted(lst)

# Append a sentinel value 'end' to the list to mark the end of processing
lst += ['end']

# Initialize variables to track the previous string and temporary count of duplicates
pre = ''
tmp_cnt = 0

# Initialize a counter to count the total number of pairs
cnt = 0

# Loop through the sorted list of strings
for i in lst:
    # If the current string is the same as the previous one, increment the temporary count
    if i == pre:
        tmp_cnt += 1
    else:
        # If the current string is different, calculate the number of pairs from the temporary count
        cnt += sum([j for j in range(tmp_cnt + 1)])
        # Reset the temporary count for the new string
        tmp_cnt = 0
        # Update the previous string to the current one
        pre = i

# Print the total count of pairs found
print(cnt)
