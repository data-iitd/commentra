# Read the number of pairs from user input
n = int(input())

# Read n pairs of integers into a list of lists
ls = [list(map(int, input().split())) for i in range(n)]

# Sort the list of pairs based on the sum of each pair in descending order
ls = sorted(ls, key=lambda x: sum(x), reverse=True)

# Calculate the total score for Taka by summing the first element of each pair at even indices
taka = sum([ls[i][0] for i in range(0, len(ls), 2)])

# Calculate the total score for Aoki by summing the second element of each pair at odd indices
aoki = sum([ls[i][1] for i in range(1, len(ls), 2)])

# Print the difference between Taka's score and Aoki's score
print(taka - aoki)
