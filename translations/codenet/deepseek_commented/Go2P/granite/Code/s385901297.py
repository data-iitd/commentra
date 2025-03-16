

ns = list(map(int, input().split())) # Read four integers from the input line and store them in the list ns
ns.sort() # Sort the list ns in ascending order
if ns == [1, 4, 7, 9]: # Check if the sorted list ns contains the numbers 1, 4, 7, and 9 in that order
    print("YES") # Print "YES" if the condition is true
else:
    print("NO") # Print "NO" if the condition is false

