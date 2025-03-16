def print(x, n):
    max_value = n * 2 - 1
    if x == 1 or x == max_value:
        print("No")
        return
    print("Yes")
    separator = "\n"
    ans = ""
    for e in range(x + n - 1, x + n + max_value - 1):
        ans += str((e % max_value + 1)) + separator
    print(ans)


# Read input
n = int(input())
x = int(input())

# Call the print function with the input values
print(x, n)
