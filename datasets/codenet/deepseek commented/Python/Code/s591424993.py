
d, g = list(map(int, input().split()))
# Read the number of dishes and the target score

pc = [list(map(int, input().split())) for _ in range(d)]
# Read the points and bonuses for each dish

ans = float("inf")
# Initialize the minimum number of dishes to solve to infinity

for bit in range(1 << d):
    # Iterate over all possible combinations of dishes being solved
    count = 0
    sum = 0
    nokori = set(range(1, d + 1))
    # Initialize the count of dishes solved and the total score to zero, and create a set of remaining dishes

    for i in range(d):
        if bit & (1 << i):
            sum += pc[i][0] * (i + 1) * 100 + pc[i][1]
            count += pc[i][0]
            nokori.discard(i + 1)
    # For each dish, if it's part of the current combination, add its score to sum and increment count, then remove it from nokori

    if sum < g:
        use = max(nokori)
        n = min(pc[use-1][0], -(-(g - sum) // (use * 100)))
        count += n
        sum += n * use * 100
    # If the current sum is less than the target score, find the most difficult remaining dish, calculate how many of it are needed, and update sum and count

    if sum >= g:
        ans = min(ans, count)
    # If the current sum is greater than or equal to the target score, update ans with the minimum of ans and count

print(ans)
# Print the minimum number of dishes needed to reach or exceed the target score

