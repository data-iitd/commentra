N, K = map(int, input().split())  # 1. Reading the values of N and K from the standard input.

v = list(map(int, input().split()))  # 2. Initializing a list to store N integers and reading them from the standard input.

# 4. Calculating the number of groups that can be formed using the formula ceil((N-1) / (K-1)).
count = (N - 1 + (K - 2)) // (K - 1)  # Using integer division to mimic the ceiling behavior.
print(count)  # 5. Outputting the calculated count.
# <END-OF-CODE>
