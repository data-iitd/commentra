def get_nums(num, t):
    # This function distributes the value t among num parts.
    # It calculates the base number for each part by dividing t by num.
    # It adds 1 to the base number for the first t % num parts.
    return [t // num + 1 if i in range(t % num) else t // num for i in range(num)]

# Read input values for n, k, l, r, sa, and sk
n, k, l, r, sa, sk = map(int, input().split())

# Use the get_nums function to calculate the distribution of sk and sa - sk
ans = get_nums(k, sk) + get_nums(n - k, sa - sk)

# Print the result as a space-separated string of numbers
print(' '.join(map(str, ans)))
