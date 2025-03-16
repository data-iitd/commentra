

n = int(input()) # Read the integer n
s = input() # Read the string s

rc = 0 # Counter for 'R' characters
gc = 0 # Counter for 'G' characters
bc = 0 # Counter for 'B' characters

# Count the number of 'R', 'G', and 'B' characters in the string s
for i in range(len(s)):
    if s[i] == 'R':
        rc += 1
    elif s[i] == 'G':
        gc += 1
    else:
        bc += 1

result = rc * gc * bc # Calculate the initial product of counts

# Iterate through possible pairs of indices i and k where i < k
for i in range(1, n + 1):
    for k in range(i + 1, n + 1):
        if (i + k) % 2 == 0: # Check if the sum of indices is even
            is = s[i - 1] # Character at index i-1
            ks = s[k - 1] # Character at index k-1
            js = s[(i + k) // 2 - 1] # Character at the middle index
            
            # Check if the characters are all different and not equal to each other
            if is!= ks and ks!= js and js!= is:
                result -= 1 # Decrement the result if conditions are met

print(result) # Print the final result

