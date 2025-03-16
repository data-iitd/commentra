
# Declare and initialize two integer variables n and m using input()
n, m = map(int, input().split())

# Calculate the value of x using the given formula
x = m*1900 + (n-m)*100

# Print the result using print()
print(x * 2**m)

# 