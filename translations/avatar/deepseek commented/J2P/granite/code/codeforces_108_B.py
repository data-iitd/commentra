

n = int(input()) # Read the size of the array
a = list(map(int, input().split())) # Populate the array with n integers
a.sort() # Sort the array
for i in range(n - 1): # Iterate through the array
    if a[i + 1] < a[i] * 2 and a[i]!= a[i + 1]: # Check if any element is less than twice the previous element
        print("YES") # Print "YES"
        break # Exit the loop after printing "YES"
else:
    print("NO") # Print "NO" if no such condition is found

