import sys

def next_line():
    return sys.stdin.readline().strip()

def next_ints_line():
    return list(map(int, next_line().split()))

def max_value(*args):
    return max(args)

def min_value(*args):
    return min(args)

def pow_int(a, e):
    if a < 0 or e < 0:
        raise ValueError("[argument error]: pow_int does not accept negative integers")
    return int(a ** e)

def abs_int(a):
    return abs(a)

def delete_element(s, i):
    if i < 0 or len(s) <= i:
        raise IndexError("[index error]")
    return s[:i] + s[i+1:]

def concat(s, t):
    return s + t

# Main function
x = next_ints_line()[0]
i = 1
sum_value = 0
while True:
    sum_value += i
    if sum_value >= x:
        break
    i += 1
print(i)

# <END-OF-CODE>
