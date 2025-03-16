

str = [] # Initialize an empty list to store the input strings
for i in range(4): # Read input strings and append them to the list
    str.append(input())

yes = 0 # Initialize a variable to keep track of whether a match is found
for u in range(2): # Compare characters in the list
    for i in range(2):
        if (str[u][i] == str[u][i+1] and (str[u+1][i] == str[u][i] or str[u+1][i+1] == str[u][i])) or (str[u+1][i] == str[u+1][i+1] and (str[u][i] == str[u+1][i] or str[u][i+1] == str[u+1][i+1])):
            yes = 1 # Set the variable to 1 if a match is found
            print("YES") # Print "YES" if a match is found
            break # Exit the inner loop if a match is found
    if yes == 1:
        break # Exit the outer loop if a match is found

if yes == 0: # Print "NO" if no match is found
    print("NO")

