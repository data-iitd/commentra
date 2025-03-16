
import sys

def main():
    n, t, a = map(float, sys.stdin.readline().split())
    heights = list(map(float, sys.stdin.readline().split()))

    min_diff = abs(t - heights[0] * 0.006 - a)
    min_idx = 0
    for i, h in enumerate(heights[1:]):
        diff = abs(t - h * 0.006 - a)
        if diff < min_diff:
            min_diff = diff
            min_idx = i + 1
    print(min_idx + 1)

if __name__ == "__main__":
    main()

