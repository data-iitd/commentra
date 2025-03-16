
# <START-OF-CODE>
import sys

def main():
    n = int(sys.stdin.readline())
    arr = [float(sys.stdin.readline()) for _ in range(2*n)]
    sum_before = sum(arr)
    non_int = sum(1 for x in arr if x!= int(x))
    sum = sum(int(x) for x in arr)
    max_sum = min(n, non_int) + sum
    min_sum = max(0, non_int - n) + sum
    ans = min(1 - (sum_before - int(sum_before)), int(sum_before) - max_sum)
    print("%.3f" % ans)

if __name__ == '__main__':
    main()
# 