
# Initialize a new scanner to read from standard input
sc = input()

# nextInt reads the next integer from standard input
def nextInt():
    return int(sc)

# scanNums reads a specified number of integers from standard input and returns them as a list
def scanNums(len):
    nums = []
    for i in range(len):
        num = nextInt()
        nums.append(num)
    return nums

# pattern1 calculates a specific pattern based on the first five integers in the list
def pattern1(l):
    n = (l[0]*l[3]) + (l[1]*l[4])
    return n

# pattern2 calculates another pattern based on the maximum of the last two integers
def pattern2(l):
    n = 2 * l[2] * max(l[3], l[4])
    return n

# pattern3 calculates a third pattern that combines the minimum value and a function call
def pattern3(l):
    n = 2*l[2]*min(l[3], l[4]) + (doch(l))
    return n

# min returns the minimum value from a variable number of integer arguments
def min(nums):
    if len(nums) == 0:
        raise ValueError("function min() requires at least one argument.")
    res = nums[0]
    for i in range(len(nums)):
        res = min(res, nums[i])
    return res

# max returns the maximum value from a variable number of integer arguments
def max(nums):
    if len(nums) == 0:
        raise ValueError("function max() requires at least one argument.")
    res = nums[0]
    for i in range(len(nums)):
        res = max(res, nums[i])
    return res

# doch calculates a value based on the difference between the last two integers in the list
def doch(l):
    if l[3] > l[4]:
        return l[0] * (l[3] - l[4])
    else:
        return l[1] * (l[4] - l[3])

# main function where the program execution begins
def main():
    len = 5
    l = scanNums(len)
    # Print the minimum value from the three calculated patterns
    print(min(pattern1(l), pattern2(l), pattern3(l)))

