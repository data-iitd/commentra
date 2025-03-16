
import sys

def main():
    n = int(sys.stdin.readline())
    aa = list(map(int, sys.stdin.readline().split()))
    cumsum = CumSum(aa)
    #print(cumsum)
    ans = 2020202020
    for i in range(1, len(cumsum)-1):
        ans = min(ans, abs(cumsum[len(cumsum)-1]-cumsum[i]-(cumsum[i]-cumsum[0])))
    print(ans)

def CumSum(nums):
    sums = [0]
    for i in range(len(nums)):
        sums.append(sums[i]+nums[i])
    return sums

def min(nums):
    if len(nums) == 0:
        raise Exception("function min() requires at least one argument.")
    res = nums[0]
    for i in range(len(nums)):
        res = min(res, nums[i])
    return res

def abs(a):
    if a >= 0:
        return a
    else:
        return -a

if __name__ == "__main__":
    main()

