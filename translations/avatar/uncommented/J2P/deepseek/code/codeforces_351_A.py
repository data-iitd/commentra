import sys

def main():
    n = int(sys.stdin.readline().strip())
    tokens = list(map(float, sys.stdin.readline().strip().split()))
    arr = []
    non_int = 0
    sum_before = 0
    sum_floored = 0
    
    for num in tokens:
        sum_before += num
        if num != int(num):
            non_int += 1
        sum_floored += int(num)
        arr.append(num)
    
    max_sum = min(n, non_int) + sum_floored
    min_sum = max(0, non_int - n) + sum_floored
    ans = 0
    
    if min_sum > sum_before:
        ans = min_sum - sum_before
    elif max_sum < sum_before:
        ans = sum_before - max_sum
    else:
        x = sum_before - int(sum_before)
        ans = min(1 - x, x)
    
    print("{:.3f}".format(ans))

if __name__ == "__main__":
    main()
