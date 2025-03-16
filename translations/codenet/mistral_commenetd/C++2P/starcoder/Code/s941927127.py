
# Declare a string variable named W to store the input word
W = raw_input()

# Sort the characters in the string W in ascending order using the sort function from the <algorithm> library
W = sorted(W)

# Initialize a string iterator named itr to point to the first character in the sorted string W
itr = W[0]

# Loop through the sorted string W using a for loop, with the loop condition that itr does not point to the end of the string
for i in range(len(W)-1):
  # Check if the current character and the next character in the string are the same
  if W[i]!= W[i+1]:
    # If they are not the same, print "No" to the standard output stream and return from the main function
    print "No"
    return 0

# If the loop completes without finding any pair of non-identical characters, print "Yes" to the standard output stream
print "Yes"

# Return 0 to indicate successful execution of the main function
return 0

