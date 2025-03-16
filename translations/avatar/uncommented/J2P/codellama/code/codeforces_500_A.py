
import sys

def dfs(currpos, arr, target):
    if currpos == target:
        return True
    if currpos == len(arr) + 1:
        return False
    teleport = dfs(currpos + arr[currpos - 1], arr, target)
    if teleport:
        return True
    return False

if __name__ == "__main__":
    sc = sys.stdin
    n = int(sc.readline())
    goal = int(sc.readline())
    arr = [int(i) for i in sc.readline().split()]
    isFound = dfs(1, arr, goal)
    if isFound:
        print("YES")
    else:
        print("NO")
    sc.close()

