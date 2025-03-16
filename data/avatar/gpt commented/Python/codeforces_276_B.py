# Read input and convert it to a list of characters
s = list(input())

# Initialize a flag variable and a dictionary to count occurrences of each character
x = True
dt = {}

# Count the occurrences of each character in the input list
for i in s:
    if i in dt:
        dt[i] += 1  # Increment the count if the character is already in the dictionary
    else:
        dt[i] = 1   # Initialize the count to 1 if the character is not in the dictionary

# Initialize a counter for odd occurrences and a flag variable
cnt = 0
x = True

# Check the counts of each character to determine the number of odd occurrences
for key, value in dt.items():
    if value % 2 != 0 and cnt < 1:
        cnt += 1  # Count the first odd occurrence
    elif value % 2 != 0 and cnt >= 1:
        x = False  # More than one odd occurrence found, set flag to False
        break

# Determine the output based on the number of odd occurrences and the length of the input
if x:
    print("First")  # If there are no more than one odd occurrences, print "First"
elif not x and len(s) % 2 == 0:
    print("Second")  # If there are more than one odd occurrences and the length is even, print "Second"
elif not x and len(s) % 2 != 0:
    print("First")  # If there are more than one odd occurrences and the length is odd, print "First"
