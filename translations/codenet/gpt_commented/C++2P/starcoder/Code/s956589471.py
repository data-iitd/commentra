# Declare variables to hold input values
a, b, c, d, e, k = map(int, input().split())

# Check if the difference between e and a is less than or equal to k
# If true, print "Yay!", otherwise print ":("
print("Yay!" if e - a <= k else ":(")

# 