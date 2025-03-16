# This line takes two integers, n and k, as input from the user.
n, k = map(int, input().split())

# This line prints the sum of the first k smallest numbers from the list of integers input in the next line.
print(sum(sorted(list(map(int, input().split())))[:k]))
