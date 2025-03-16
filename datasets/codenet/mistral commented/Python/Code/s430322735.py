
n = int(input())  # Read the number of strings from the user
lst = []         # Initialize an empty list to store the sorted strings
pair = 0         # Initialize a counter for pairs of identical strings

for i in range(n):  # Iterate through each string input by the user
	st = ''.join(sorted(list(input())))  # Sort the characters in the string and join them into a single string
	lst.append(st)                     # Append the sorted string to the list

lst = sorted(lst)  # Sort the list of strings in ascending order
lst += ['end']    # Add a sentinel value 'end' to the end of the list

pre = ''          # Initialize an empty string to store the previous string
tmp_cnt = 0       # Initialize a counter for the number of consecutive identical strings
cnt = 0           # Initialize a counter for the total number of pairs in the list

for i in lst:     # Iterate through each string in the sorted list
	if i == pre:  # Check if the current string is the same as the previous one
		tmp_cnt += 1  # Increment the counter for consecutive identical strings
	else:
		cnt += sum([j for j in range(tmp_cnt + 1)])  # Add the number of pairs of consecutive identical strings to the total count
		tmp_cnt = 0  # Reset the counter for consecutive identical strings
	pre = i        # Update the previous string to the current string

print (cnt)       # Print the total number of pairs of consecutive identical strings in the list.