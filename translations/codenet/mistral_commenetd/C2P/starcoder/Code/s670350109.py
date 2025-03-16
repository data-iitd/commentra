
# Include standard input/output library
# Include string manipulation library

str1 = input() # Read the first string from the user
print("First string: " + str1) # Print the first string for verification

str2 = input() # Read the second string from the user
print("Second string: " + str2) # Print the second string for verification

i = len(str1) # Get the length of the first string
t = i - 1 # Set the index variable t to the last index of the first string

# Check if the lengths of the two strings are equal
if (len(str1)!= len(str2)):
    print("NO") # If the lengths are not equal, print "NO" and exit
else:
    # Reverse the first string and store it in temp array
    j = 0
    while (str1[j]!= '\0'):
        temp[j] = str1[t] # Swap the characters at the current indices of str1 and temp
        j = j + 1 # Increment j
        t = t - 1 # Decrement t
    # Compare the reversed first string with the second string
    t = 0
    i = 0
    while (temp[i]!= '\0'): # Iterate through the reversed first string
        if (temp[i] == str2[i]): # Check if the corresponding characters are equal
            t = t + 1 # Increment the counter if they are equal
        i = i + 1 # Increment i
    # Check if all characters are equal and print the result accordingly
    if (len(str2) == t):
        print("YES") # If all characters are equal, print "YES"
    else if (len(str2)!= t):
        print("NO") # If any character is different, print "NO"

