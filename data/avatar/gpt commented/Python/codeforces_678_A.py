# Read two integers from input, separated by a space
vamshi, z = map(int, input().split())

# Calculate the smallest multiple of z that is greater than or equal to vamshi
# This is done by performing integer division of vamshi by z, adding 1, and then multiplying by z
result = (vamshi // z + 1) * z

# Print the result
print(result)
