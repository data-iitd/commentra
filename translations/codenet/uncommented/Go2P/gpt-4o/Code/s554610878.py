import sys

initial_buf_size = 10000
max_buf_size = 1000000
mod = 10**9 + 7

def main():
    week = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]
    s = get_string()
    index = -1
    for i, day in enumerate(week):
        if s == day:
            index = i
            break

    print(7 - index)

def get_int():
    return int(sys.stdin.readline().strip())

def get_string():
    return sys.stdin.readline().strip()

def abs_value(a):
    return abs(a)

def pow_value(p, q):
    return p ** q

def min_value(*nums):
    if len(nums) == 0:
        raise ValueError("function min_value() requires at least one argument.")
    return min(nums)

def max_value(*nums):
    if len(nums) == 0:
        raise ValueError("function max_value() requires at least one argument.")
    return max(nums)

def str_search(a, b):
    return b in a

def print_int_array(array):
    print(array)

def calc_mod(x):
    return x % mod

if __name__ == "__main__":
    main()

# <END-OF-CODE>
