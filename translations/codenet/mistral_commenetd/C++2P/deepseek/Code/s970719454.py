# Including necessary headers
# ...

# Initializing arrays
here = [0] * 100001
dp1 = [0] * 100001
dp2 = [0] * 100001

# Reading input
while True:
    n, m = map(int, input().split())
    if n == 0:
        break

    # Resetting the arrays for new input
    here = [0] * 100001
    dp1 = [0] * 100001
    dp2 = [0] * 100001

    # Reading queries
    queries = list(map(int, input().split()))
    for a in queries:
        # Setting the corresponding element of 'here' array to 1
        here[a] = 1

    # Calculating the maximum length of a subsequence without any house
    maxi1 = 0
    for i in range(1, n + 1):
        if here[i] == 1:
            dp1[i] = dp1[i - 1] + 1
        maxi1 = max(dp1[i], maxi1)

    # Calculating the maximum length of a subsequence with at least one house
    maxi2 = 0
    for i in range(1, n + 1):
        if here[i] == 1:
            dp2[i] = dp2[i - 1] + 1
        else:
            dp2[i] = dp1[i - 1] + 1
        maxi2 = max(dp2[i], maxi2)

    # Printing the result
    if 0 not in queries:
        print(maxi1)
    else:
        print(maxi2)
