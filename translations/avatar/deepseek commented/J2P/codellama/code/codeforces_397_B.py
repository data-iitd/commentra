
import sys

# Read the number of test cases.
t = int(input())

# Process each test case.
while t > 0:
    # Read the values of n, a, and b.
    n, a, b = map(int, input().split())

    # Check if n is less than a.
    if n < a:
        print("No")
        t -= 1
        continue

    # Check if a is equal to b.
    if a == b:
        if n % a == 0:
            print("Yes")
        else:
            print("No")
        t -= 1
        continue

    # Calculate x as b / (b - a).
    x = b // (b - a)

    # Check if n is greater than x * a.
    if n > x * a:
        print("Yes")
        t -= 1
        continue

    # Perform binary search to find the minimum ans.
    low = 1
    high = x + 1
    ans = 1
    while low <= high:
        mid = (low + high) // 2
        if mid * a < n:
            low = mid + 1
        else:
            ans = mid
            high = mid - 1

    # Check if n lies between (ans - 1) * b and ans * a.
    if n > (ans - 1) * b and n < ans * a:
        print("No")
    else:
        print("Yes")

    t -= 1

# End of code.
