

W = input() # Read the input word from the standard input stream using input()
W = sorted(W) # Sort the characters in the string W in ascending order using the sorted() function

for i in range(len(W)-1): # Loop through the sorted string W using a for loop, with the loop condition that i is less than the length of the string minus 1
  if W[i]!= W[i+1]: # Check if the current character and the next character in the string are the same
    print("No") # If they are not the same, print "No" to the standard output stream
    exit() # Exit the program

print("Yes") # If the loop completes without finding any pair of non-identical characters, print "Yes" to the standard output stream

