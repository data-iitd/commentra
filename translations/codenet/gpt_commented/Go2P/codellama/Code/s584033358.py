
# Declare two integer variables n and k
n, k = map(int, input().split())

# Check if k is less than or equal to half of n (rounded up)
if k <= (n+n%2)/2:
    # If the condition is true, print "YES"
    print("YES")
else:
    # If the condition is false, print "NO"
    print("NO")

