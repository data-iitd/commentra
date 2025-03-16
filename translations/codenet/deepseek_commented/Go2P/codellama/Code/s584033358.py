
# Declare integer variables n and k to store input values
n, k = map(int, input().split())

# Check if k is less than or equal to half of n, considering n's parity
if k <= (n+n%2)/2:
    # If true, print "YES"
    print("YES")
else:
    # If false, print "NO"
    print("NO")

