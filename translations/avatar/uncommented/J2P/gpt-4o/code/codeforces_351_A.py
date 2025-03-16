import sys
import math

def main():
    n = int(sys.stdin.readline().strip())
    arr = list(map(float, sys.stdin.readline().strip().split()))
    
    non_int = 0
    sum_before = 0
    sum_floor = 0
    
    for num in arr:
        sum_before += num
        if num != math.floor(num):
            non_int += 1
        sum_floor += math.floor(num)
    
    max_sum = min(n, non_int) + sum_floor
    min_sum = max(0, non_int - n) + sum_floor
    
    if min_sum > sum_before:
        ans = min_sum - sum_before
    elif max_sum < sum_before:
        ans = sum_before - max_sum
    else:
        x = sum_before - math.floor(sum_before)
        ans = min(1 - x, x)
    
    print(f"{ans:.3f}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
