
import sys

def str2List(str):
    vArrStr = str.split(" ")
    ret = {}
    key = 0
    for val in vArrStr:
        ret[key] = int(val)
        key += 1
    return ret

def main():
    # Step 1: Read the input value `n` which represents the number of elements.
    n = int(sys.stdin.readline())
    
    # Step 2: Read the values of `v` (values) and store them in a list `vList`.
    vStr = sys.stdin.readline()
    vList = str2List(vStr)
    
    # Step 3: Read the values of `c` (costs) and store them in a list `cList`.
    cStr = sys.stdin.readline()
    cList = str2List(cStr)
    
    # Step 4: Initialize a variable `max` to keep track of the maximum profit.
    max = 0
    
    # Step 5: Iterate through the elements, calculate the profit for each element, and update `max` if the profit is positive.
    for i in range(n):
        profit = vList[i] - cList[i]
        if profit > 0:
            max += profit
    
    # Step 6: Print the maximum profit.
    print(max)

if __name__ == "__main__":
    main()

# 