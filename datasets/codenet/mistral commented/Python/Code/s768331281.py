# Define variables N and L, and assign them the values obtained from the input
N, L = map(int, input().split())

# Use map() function to apply int() conversion to each element of the list obtained from the input,
# and then unpack the tuple returned by map() into N and L

# Define a list called S, and populate it with N strings obtained by reading each line of input
S = [input().rstrip() for _ in range(N)]

# Use join() method to concatenate all the strings in the list S into a single string
sorted_string = ''.join(S)

# Use sorted() function to sort that string alphabetically
sorted_string = ''.join(sorted(sorted_string))

# Finally, print the sorted string
print(sorted_string)