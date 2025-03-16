
# Read two long long integers from standard input
a,b = map(int,input().split())

# Compute the maximum value among a+b, a-b, and a*b
print(max(a+b,max(a-b,a*b)))

# 