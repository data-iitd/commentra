
import sys

N = int(input())
A = list(map(int, input().split()))
sum = 0
wa = 0
sa = []
ans = 0
shou = 0
min = 1123456789

# Calculate the sum and wa
for i in range(N):
    sum += A[i]
    wa += i+1

# Check if the sum is divisible by wa
if sum % wa!= 0:
    ans = 0
else:
    shou = sum // wa

    # Calculate the differences between consecutive elements and store them in the array sa
    for i in range(N):
        sa.append(A[(i+1)%N] - A[i] - shou)

    # Check if all differences are less than or equal to 0 and divisible by N
    for i in range(N-1):
        if sa[i] <= 0 and sa[i] % N == 0:
            ans = 1
        else:
            ans = 0
            break

# Print "YES" if ans is 1, otherwise print "NO"
if ans == 1:
    print("YES")
else:
    print("NO")

