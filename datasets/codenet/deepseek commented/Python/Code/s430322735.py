
n = int(input())  # Take an integer input representing the number of strings
lst = []  # Initialize an empty list to store sorted versions of input strings
pair = 0  # Initialize a variable to count pairs of identical strings

# Loop to take n strings, sort their characters, and append to lst
for i in range(n):
    st = ''.join(sorted(list(input())))  # Sort the characters of the input string
    lst.append(st)  # Append the sorted string to lst

lst = sorted(lst)  # Sort the list of sorted strings
lst += ['end']  # Append 'end' to mark the end of the list

pre = ''  # Initialize a variable to keep track of the previous string
tmp_cnt = 0  # Initialize a variable to count consecutive identical strings
cnt = 0  # Initialize a variable to store the final count of pairs

# Loop to count pairs of identical strings
for i in lst:
    if i == pre:  # If the current string is the same as the previous one
        tmp_cnt += 1  # Increment the temporary count
    else:
        cnt += sum([j for j in range(tmp_cnt + 1)])  # Update the count with the sum of pairs
        tmp_cnt = 0  # Reset the temporary count
        pre = i  # Update the previous string

print(cnt)  # Print the final count of pairs of identical strings

