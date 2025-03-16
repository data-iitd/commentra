s = list(input())  # Convert the input string into a list of characters
x = True  # Initialize a boolean variable to track the result
dt = {}  # Initialize an empty dictionary to store character frequencies

# Iterate over each character in the input string and update the frequency count in the dictionary
for i in s:
    if i in dt:
        dt[i] += 1
    else:
        dt[i] = 1

cnt = 0  # Initialize a counter to keep track of characters with an odd frequency
x = True  # Reset the boolean variable to track the result

# Iterate over the items in the dictionary to determine if there is more than one character with an odd frequency
for key, value in dt.items():
    if value % 2 != 0 and cnt < 1:
        cnt += 1
    elif value % 2 != 0 and cnt >= 1:
        x = False
        break

# Determine the output based on the value of cnt and the length of the input string
if x:
    print("First")  # Print "First" if there is at most one character with an odd frequency
elif not x and len(s) % 2 == 0:
    print("Second")  # Print "Second" if there is more than one character with an odd frequency and the length of the input string is even
elif not x and len(s) % 2 != 0:
    print("First")  # Print "First" if there is more than one character with an odd frequency and the length of the input string is odd
