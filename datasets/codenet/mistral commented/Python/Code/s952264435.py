
N, M = map(int, input().split())
# Read the first two elements of the input as integers N and M

A = list(map(int, input().split()))
# Read the rest of the input as a list A

A_sum = sum(A)
# Calculate the sum of all the elements in the list A

if N >= A_sum:
 print(N - A_sum)
# If N is greater than or equal to the sum of all the elements in A,
 # print the difference between N and the sum of A
else:
 print("-1")
# Otherwise, print "-1"