import sys; # Importing the sys module for reading input from the console

# Reading two lines of input: S and T
S = sys.stdin.readline().strip();
T = sys.stdin.readline().strip();

# Defining an array of lowercase letters from 'a' to 'z'
A = [ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" ];

# Initializing a boolean variable to track the result
res = True;

# Iterating through each letter in the array A
for s in A:
    # Finding the index of the current letter in string S
    sIdx = S.find(s);
    
    # If the letter is not found in S, continue to the next letter
    if sIdx < 0: continue;
    
    # Getting the corresponding character from T at the same index
    t = str(T[sIdx]);
    idx = 0; # Initializing index for searching
    
    # Loop to check the correspondence of characters in S and T
    while idx < len(S):
        # If the current letter s is found in S starting from idx
        if S.find(s, idx) >= 0:
            # Check if the index of s in S matches the index of t in T
            if S.find(s, idx)!= T.find(t, idx):
                # If they do not match, set res to false and break
                res = False;
                break;
            else:
                # If they match, move the index to the next position
                idx = S.find(s, idx) + 1;
        # If the character t is found in T but s is not found in S
        elif T.find(t, idx) >= 0:
            # Set res to false and break
            res = False;
            break;
        else:
            # Break the loop if neither character is found
            break;
    # If a mismatch was found, break out of the outer loop
    if not res: break;

# Output the result based on the value of res
if res: 
    print("Yes"); # If res is true, print "Yes"
else: 
    print("No"); # If res is false, print "No"

# 