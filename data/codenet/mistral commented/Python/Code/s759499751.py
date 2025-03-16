# Read the input: two integers n and k, and the string a
n, k = map(int, input().split())
a = list(input())

# Initialize a list c of length n with zeros
c = [0] * n

# Iterate through the string from the second character to the last character
for i in range(1, n):
    # If the current character is "C" and the previous character is "A",
    # then add the number of consecutive "A"s before the previous character
    # to the current character's count
    if a[i] == "C" and a[i-1] == "A":
        c[i] = c[i-1] + 1
    # Otherwise, the count remains the same as the previous character
    else:
        c[i] = c[i-1]

# Iterate through the queries k times
for w in range(k):
    # Read the left and right indices l and r for the current query
    l, r = map(int, input().split())
    # Print the difference between the number of consecutive "A"s before the right index
    # and the number of consecutive "A"s before the left index
    print(c[r-1] - c[l-1])
