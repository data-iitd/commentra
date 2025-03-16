

# Read the first string from the user
str1 = input("Enter the first string: ")
print("First string:", str1) # Print the first string for verification

# Read the second string from the user
str2 = input("Enter the second string: ")
print("Second string:", str2) # Print the second string for verification

# Check if the lengths of the two strings are equal
if len(str1)!= len(str2):
    print("NO") # If the lengths are not equal, print "NO" and exit
else:
    # Reverse the first string and store it in temp array
    temp = str1[::-1]
    # Compare the reversed first string with the second string
    t = 0
    for i in range(len(temp)): # Iterate through the reversed first string
        if temp[i] == str2[i]: # Check if the corresponding characters are equal
            t += 1 # Increment the counter if they are equal
    # Check if all characters are equal and print the result accordingly
    if len(str2) == t:
        print("YES") # If all characters are equal, print "YES"
    else:
        print("NO") # If any character is different, print "NO"

print("