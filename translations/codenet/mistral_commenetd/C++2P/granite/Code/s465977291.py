

# Read two integers 'n' and 'd' from the standard input
n, d = map(int, input().split())

# Calculate the value of 'a' as 'd' multiplied by 2 and adding 1
a = d*2+1

# Use the ceil function to find the smallest integer greater than or equal to the result of dividing 'n' by 'a'
# Print the result to the standard output
print(ceil(n/a))

# End of code
