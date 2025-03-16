
import sys

def nextInt():
    return int(input())

def scanNums(len):
    nums = []
    for i in range(len):
        num = nextInt()
        nums.append(num)
    return nums

def pattern1(l):
    n = (l[0]*l[3])+(l[1]*l[4])
    return n

def pattern2(l):
    n =2*l[2]*max(l[3],l[4])
    return n

def pattern3(l):
    n = 2*l[2]*min(l[3],l[4])+(doch(l))
    return n

def min(*nums):
    if len(nums) == 0:
        raise Exception("funciton min() requires at least one argument.")
    res = nums[0]
    for i in range(len(nums)):
        res = min(res, nums[i])
    return res

def max(*nums):
    if len(nums) == 0:
        raise Exception("funciton max() requires at least one argument.")
    res = nums[0]
    for i in range(len(nums)):
        res = max(res, nums[i])
    return res

def doch(l):
    if l[3]>l[4]:
        return l[0] * (l[3]-l[4])
    else:
        return l[1] * (l[4]-l[3])

if __name__ == "__main__":
    len = 5
    l = scanNums(len)
    print(min(pattern1(l),pattern2(l), pattern3(l)))

