# Take the number of test cases as input
n = int(input())

# Initialize a list 't' with 0 as the first element and followed by the given input list
t = [0] + list(map(int, input().split()))

# Initialize a list 'a' with 0 as the first element and followed by the given input list
a = [0] + list(map(int, input().split()))

# Initialize empty lists 'ans' and 'cnt'
ans, cnt = [], [0 for i in range(n+1)]

# Iterate through each element in list 'a' and increment the count of its corresponding index in list 'cnt'
for i in a:
    cnt[i] += 1

# Iterate through each index from 1 to n
for i in range(1, n+1):
    # If the current index in list 't' is 1
    if t[i] == 1:
        # Initialize an empty list 'crt' to store the current sequence
        crt = [i]
        # Get the current element in list 'a'
        x = a[i]
        # Continue adding elements to 'crt' as long as the corresponding index in 'cnt' has a count of 1
        while cnt[x] == 1:
            crt.append(x)
            x = a[x]
        # If the length of the current sequence is greater than the length of the current answer sequence
        if len(crt) > len(ans):
            # Update the answer sequence with the current sequence
            ans = crt[:]

# Reverse the order of elements in the answer sequence
ans.reverse()

# Print the length of the answer sequence
print(len(ans))
# Print the answer sequence with each element separated by a space
print(' '.join(map(str, ans)))
