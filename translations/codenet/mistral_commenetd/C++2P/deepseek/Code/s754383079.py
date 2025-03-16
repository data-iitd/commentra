import sys

# read string a from standard input
a = input().strip()
n = len(a)

# read string b from standard input
b = input().strip()
m = len(b)

# initialize the minimum number of differences to a large value
ans = sys.maxsize

# iterate through all possible substrings of string a that have the same length as string b
for i in range(n - m + 1):
    # initialize sum to 0, it will be used to count the number of differences between the i-th substring of string a and string b
    sum = 0

    # iterate through each character in the substring of string a and compare it with the corresponding character in string b
    for j in range(m):
        # if the characters are different, increment sum by 1
        if a[i + j] != b[j]:
            sum += 1

    # update the minimum number of differences if a smaller number is found
    ans = min(ans, sum)

# print the minimum number of differences to standard output
print(ans)

# end the program with exit code 0
