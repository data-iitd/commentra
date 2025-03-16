
def get_nums(num, t):
    """
    This function takes two arguments: an integer `num` and an integer `t`.
    It returns a list of integers obtained by dividing `t` by `num` and adding 1 to the quotient for each index `i` in the range of `t % num`.
    """
    return [t // num + 1 if i in range(t % num) else t // num for i in range(num)]

n, k, l, r, sa, sk = map(int, input().split())
"""
This line reads five integers from the standard input and assigns them to the variables `n`, `k`, `l`, `r`, and `sa`.
"""
ans = get_nums(k, sk) + get_nums(n - k, sa - sk)
"""
This line initializes the variable `ans` as the sum of two lists: the result of calling `get_nums` with arguments `k` and `sk`, and the result of calling `get_nums` with arguments `n - k` and `sa - sk`.
"""
print(' '.join(map(str, ans)))
"""
This line converts the list `ans` to a single string, separated by spaces, and prints it to the standard output.
"""