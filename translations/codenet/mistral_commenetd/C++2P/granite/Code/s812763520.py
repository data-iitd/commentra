
n = int(input()) # We read the number of elements in the strings from the standard input
a, b, c = input(), input(), input() # We read the three strings 'a', 'b', and 'c' from the standard input, one string at a time
ans = 0 # We initialize an integer variable 'ans' to 0 to store the answer

for i in range(n): # We start a for loop that iterates from 0 to 'n'-1
    if a[i] == b[i] and b[i] == c[i]: # We check if all three characters at the current index are equal
    else: # If not, we check if any two of the three characters are equal
        if a[i] == b[i] or b[i] == c[i] or a[i] == c[i]:
            ans += 1 # If so, we increment the answer by 1
        else:
            ans += 2 # If none of the above conditions are met, we increment the answer by 2

print(ans) # We print the answer to the standard output
