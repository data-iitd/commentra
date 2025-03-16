# Read two integers from standard input
N, A = map(int, input().split())

# Check if the remainder of N divided by 500 is less than or equal to A
# If true, print "Yes"; otherwise, print "No"
print("Yes" if N % 500 <= A else "No")

