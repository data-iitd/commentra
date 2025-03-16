def get_nums(num, t):
    # Generate a list of numbers based on the distribution of t across num parts
    return [t // num + 1 if i in range(t % num) else t // num for i in range(num)]

# Read input values for n, k, l, r, sa, and sk
n, k, l, r, sa, sk = map(int, input().split())

# Calculate the distribution of sk among k parts and sa - sk among the remaining n - k parts
ans = get_nums(k, sk) + get_nums(n - k, sa - sk)

# Print the result as a space-separated string
print(' '.join(map(str, ans)))
