
# <START-OF-CODE>

# Create a Scanner object to read input from the console
sc = Scanner(sys.stdin)

# Read two integers n and m from the input
n = sc.nextInt()
m = sc.nextInt()

# Check if n is zero
if n == 0:
    # If m is not zero, print "Impossible" since we cannot form a valid output
    if m!= 0:
        print("Impossible")
    # If m is also zero, print "0 0" as the valid output
    else:
        print(0, 0)
    sys.exit(0)

# Check if m is less than or equal to n
if m <= n:
    # If m is zero, set it to one to ensure valid output
    if m == 0:
        m = 1
    # Print n and the adjusted value of m
    print(n, m + n - 1)
    sys.exit(0)

# If m is greater than n, print m and the adjusted value of m
print(m, m + n - 1)

# 