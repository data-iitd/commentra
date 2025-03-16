
import sys

# Global variable to store the answer
ans = 0

# Helper function to calculate the sum of numbers based on a specific pattern
def get(a):
    ret = 0
    now = 1
    t = 1
    while True:
        if now * 10 > a:
            ret += (a - now + 1) * t
            break
        ret += now * 9 * t
        now *= 10
        t += 1
    return ret

# Binary search function to find the desired value
def binarySearch(k, l, r, x):
    if r >= l:
        mid = l + (r - l) / 2
        if mid > ans and mid * k <= x:
            ans = mid
        if k * mid == x:
            return mid
        if k * mid > x:
            return binarySearch(k, l, mid - 1, x)
        return binarySearch(k, mid + 1, r, x)
    return -1

# Setup for input and output using BufferedReader and PrintWriter
br = sys.stdin
pw = sys.stdout

# Main function where the execution starts
if __name__ == "__main__":
    gen, st, tim = map(int, br.readline().split())
    gen /= tim
    beg = st - 1
    end = 10 ** 18
    while True:
        med = (beg + end) / 2 + 1
        if get(med) - get(st - 1) > gen:
            end = med - 1
        else:
            beg = med
        if beg == end:
            pw.write(str(beg - st + 1))
            break

# 