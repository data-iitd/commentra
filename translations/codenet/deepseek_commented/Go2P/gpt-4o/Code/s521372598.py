import sys

def solve():
    n = get_int()
    as_ = get_int_slice(n)

    xs = [a - i + 1 for i, a in enumerate(as_)]
    xs.sort()  # Sort the slice xs

    b = xs[n // 2]  # Choose the median as b
    ans = sum(abs(x - b) for x in xs)
    print(ans)

def abs(n):
    return -n if n < 0 else n

# -----------------------------------------

def get_int():
    return int(sys.stdin.readline().strip())

def get_int_slice(n):
    return list(map(int, sys.stdin.readline().strip().split()))

# The main function initializes the program logic.
if __name__ == "__main__":
    solve()
    
# <END-OF-CODE>
