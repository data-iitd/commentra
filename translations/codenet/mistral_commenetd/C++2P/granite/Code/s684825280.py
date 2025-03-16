

n, k = map(int, input().split()) # Read the number of elements 'n' and the number of frequencies to consider 'k' from the standard input

cnt = [0] * (1e5 * 2 + 13) # Initialize a list 'cnt' of size 'SIZE' to store the frequency count of each element

for i in range(n): # Loop through the input elements
    x = int(input()) # Read an element 'x' from the standard input

    cnt[x] += 1 # Increment the frequency count of the element 'x' in the list 'cnt'

a = [cnt[i] for i in range(len(cnt)) if cnt[i] > 0] # Create a list 'a' to store the frequency count of each element

a.sort() # Sort the list 'a' in ascending order

ans = sum(a[:len(a) - k]) # Calculate the sum of the first 'k' frequency counts and store it in the variable 'ans'

print(ans) # Print the result 'ans' to the standard output

