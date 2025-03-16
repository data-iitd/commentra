n = int(input())  # Read the value of n from the standard input
a = int(input())  # Read the value of a from the standard input
s = list(map(int, input().split()))  # Read the elements into a list

# Sort the list in ascending order
s.sort()

# Calculate the sum of the last 'a' elements
sum_last_a = sum(s[-a:])

# Print the calculated sum to the standard output
print(sum_last_a)
