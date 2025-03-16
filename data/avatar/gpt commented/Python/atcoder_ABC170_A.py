# Read a line of input, split it into components, and convert each component to an integer
a = list(map(int, input().split()))

# Iterate over the list 'a' using enumerate to get both the index (e) and the value (i)
for e, i in enumerate(a):
    # Check if the current value is zero
    if i == 0:
        # Print the index (1-based) of the first occurrence of zero
        print(e + 1)
        # Exit the loop after finding the first zero
        break
