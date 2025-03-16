
# Read input
N = int(input())
A = list(map(int, input().split()))

# Calculate sum and wa
sum = sum(A)
wa = sum(range(1, N+1))

# Check if sum is divisible by wa
if sum % wa!= 0:
    ans = 0
else:
    # Calculate differences between adjacent elements and store in array sa
    sa = [A[(i+1)%N] - A[i] - sum//wa for i in range(N)]

    # Check if any difference is less than or equal to 0 and divisible by N
    ans = all(s > 0 and s % N == 0 for s in sa)

# Print answer
print("YES" if ans else "NO")

