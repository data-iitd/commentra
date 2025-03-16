
import sys

# Reading two lines of input: S and T
S = input()
T = input()

# Defining an array of lowercase letters from 'a' to 'z'
A = [chr(i) for i in range(ord('a'), ord('z') + 1)]

# Initializing a boolean variable to track the result
res = True

# Iterating through each letter in the array A
for s in A:
    # Finding the index of the current letter in string S
    sIdx = S.find(s)
    
    # If the letter is not found in S, continue to the next letter
    if sIdx == -1: continue
    
    # Getting the corresponding character from T at the same index
    t = T[sIdx]
    idx = 0 # Initializing index for searching
    
    # Loop to check the correspondence of characters in S and T
    while idx < len(S):
        # If the current letter s is found in S starting from idx
        if S.find(s, idx)!= -1:
            # Check if the index of s in S matches the index of t in T
            if S.find(s, idx)!= T.find(t, idx):
                # If they do not match, set res to false and break
                res = False
                break
            else:
                # If they match, move the index to the next position
                idx = S.find(s, idx) + 1
        # If the character t is found in T but s is not found in S
        elif T.find(t, idx)!= -1:
            # Set res to false and break
            res = False
            break
        else:
            # Break the loop if neither character is found
            break

# Output the result based on the value of res
if res: 
    print("Yes") # If res is true, print "Yes"
else: 
    print("No") # If res is false, print "No"

