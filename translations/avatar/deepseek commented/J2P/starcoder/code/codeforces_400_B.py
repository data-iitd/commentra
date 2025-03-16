
import sys

def main():
    n = int(sys.stdin.readline())
    m = int(sys.stdin.readline())
    arrs = []
    for i in range(n):
        arrs.append(sys.stdin.readline().strip())
    length = [0] * n
    index = 0
    returnDex = 0
    for tmp in arrs:
        dexG = tmp.find("G")
        dexS = tmp.find("S")
        if dexG > dexS:
            returnDex = -1
        length[index] = dexS - dexG
        index += 1
    set = set(length)
    if returnDex == -1:
        print(returnDex)
    else:
        print(len(set))

if __name__ == "__main__":
    main()

