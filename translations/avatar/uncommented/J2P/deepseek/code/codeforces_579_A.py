def count_ones_in_binary(n):
    s = ""
    while n > 0:
        x = n % 2
        n //= 2
        s += str(x)
    ans = 0
    for char in s:
        if char == '1':
            ans += 1
    return ans

# Example usage:
n = int(input())
print(count_ones_in_binary(n))
