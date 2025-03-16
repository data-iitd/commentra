# Initialize an empty list 's' to store input elements
s = list(input())

# Initialize an empty dictionary 'dt' to store the count of each unique element
dt = {}

# Set a boolean variable 'x' to True to indicate whether there is an odd count element in the list
x = True

# Iterate through each element 'i' in the list 's'
for i in s:
    # Check if the element 'i' already exists as a key in the dictionary 'dt'
    if i in dt:
        # If it does, increment its value by 1
        dt[i] += 1
    else:
        # If not, add it as a new key with a value of 1
        dt[i] = 1

# Initialize a counter 'cnt' to 0 and set 'x' to True
cnt = 0
x = True

# Iterate through each key-value pair ('key', 'value') in the dictionary 'dt'
for key, value in dt.items():
    # If the value is odd and 'cnt' is less than 1, increment 'cnt' by 1
    if value % 2 != 0 and cnt < 1:
        cnt += 1
    # If the value is odd and 'cnt' is already greater than or equal to 1, set 'x' to False and break the loop
    elif value % 2 != 0 and cnt >= 1:
        x = False
        break

# After the loop, check the value of 'x'
if x:
    # If it is True, print "First"
    print("First")
elif not x and len(s) % 2 == 0:
    # If it is False and the length of the list 's' is even, print "Second"
    print("Second")
elif not x and len(s) % 2 != 0:
    # If it is False and the length of the list 's' is odd, print "First"
    print("First")
