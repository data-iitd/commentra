import sys

def read_int():
    return int(sys.stdin.readline().strip())

def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

def solve(n, k, logs_length):
    left, right = 1, int(1e9) + 1000
    while left < right:
        mid = (left + right) // 2
        if can_cut(mid, logs_length, k):
            right = mid
        else:
            left = mid + 1
    return left

def can_cut(mid, logs_length, k):
    for log in logs_length:
        k -= (log + mid - 1) // mid - 1
        if k < 0:
            return False
    return True

def main():
    n, k = read_ints()
    logs_length = read_ints()
    result = solve(n, k, logs_length)
    print(result)

if __name__ == "__main__":
    main()
