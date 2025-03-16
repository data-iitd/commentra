# Take an integer 'n' as input
n = int(input())

# Take two lists 's' and 't' of length 'n' as input
s = list(input())
t = list(input())

# Check if both lists 's' and 't' are equal or not
if s == t:
    # If they are equal, print the value of 'n'
    print(n)
else:
    # Initialize a counter 'cnt' to store the length of the longest common substring
    cnt = 0

    # Iterate through all possible substrings of 's' starting from the first character
    for i in range(n):
        # Iterate through all possible substrings of 't' starting from the first character
        for j in range(n - i):
            # Check if the substring of 's' starting from index 'i+j' is equal to the substring of 't' starting from index 'j'
            if s[i + j] != t[j]:
                # If they are not equal, break the inner loop and move to the next substring of 's'
                break

            # If they are equal and we have reached the end of the substring of 's', update the value of 'cnt'
            if j == n - i - 1:
                cnt = n - i

    # If 's' and 't' have no common substring, 'cnt' will be 0. In that case, print 2*n
    print(2 * n - cnt)
