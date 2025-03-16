

import sys

def main():
    n = int(input())
    arr = list(map(float, input().split()))
    non_int = 0
    sum_before = 0
    sum = 0

    for num in arr:
        sum_before += num
        if num!= int(num):
            non_int += 1
        sum += int(num)

    max_sum = min(n, non_int) + sum
    min_sum = max(0, non_int - n) + sum
    ans = 0

    if min_sum > sum_before:
        ans = min_sum - sum_before
    elif max_sum < sum_before:
        ans = sum_before - max_sum
    else:
        x = sum_before - int(sum_before)
        ans = min(1 - x, x)

    print(f"{ans:.3f}")

if __name__ == "__main__":
    main()

