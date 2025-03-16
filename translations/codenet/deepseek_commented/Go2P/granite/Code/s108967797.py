
import sys

def ri():
    return int(input())

def ave(s):
    return sum(s) / len(s)

def diff(a, b):
    return abs(a - b)

def main():
    n = ri()
    a = [ri() for _ in range(n)]
    ave_a = ave(a)
    min_diff = float('inf')
    ans_index = -1
    for i, v in enumerate(a):
        diff_v_ave = diff(v, ave_a)
        if diff_v_ave < min_diff:
            min_diff = diff_v_ave
            ans_index = i
    print(ans_index)

if __name__ == "__main__":
    sys.exit(main())

