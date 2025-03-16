
import bufio
import math
import os
import sys

def main():
    n, t, a = map(int, input().split())
    heights = list(map(int, input().split()))

    min_diff = abs(t - heights[0] * 0.006 - a)
    min_idx = 0
    for i, h in enumerate(heights[1:], 1):
        diff = abs(t - h * 0.006 - a)
        if diff < min_diff:
            min_diff = diff
            min_idx = i

    print(min_idx)

def abs_diff_float64(n1, n2):
    return math.fabs(n1 - n2)

def new_scanner():
    s = bufio.Scanner(sys.stdin)
    s.buffer(bytearray(10000000), 10000000)
    s.split(bufio.ScanWords)
    return s

def new_writer():
    return bufio.Writer(sys.stdout)

scanner = new_scanner()
writer = new_writer()

main()

