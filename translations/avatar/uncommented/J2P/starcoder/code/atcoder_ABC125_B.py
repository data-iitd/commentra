
# <START-OF-CODE>
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
    n = int(sys.stdin.readline())
    vStr = sys.stdin.readline()
    vList = str2List(vStr)
    cStr = sys.stdin.readline()
    cList = str2List(cStr)
    max = 0
    for i in range(n):
        profit = vList[i] - cList[i]
        if profit > 0:
            max += profit
    print(max)

if __name__ == "__main__":
    main()
# 