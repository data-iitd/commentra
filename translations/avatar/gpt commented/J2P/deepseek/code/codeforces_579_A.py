def count_ones_in_binary(n):
    s = ""
    while n > 0:
        x = n % 2
        n = n // 2
        s += str(x)
    ans = 0
    for char in s:
        if char == '1':
            ans += 1
    return ans

# Reading an integer input from the user
n = int(input())

# Printing the total count of '1's in the binary representation
print(count_ones_in_binary(n))
