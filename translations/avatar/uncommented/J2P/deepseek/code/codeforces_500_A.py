def dfs(currpos, arr, target):
    if currpos == target:
        return True
    if currpos > len(arr):
        return False
    return dfs(currpos + arr[currpos - 1], arr, target) or dfs(currpos + 1, arr, target)

def main():
    n = int(input())
    goal = int(input())
    arr = list(map(int, input().split()))
    is_found = dfs(1, arr, goal)
    if is_found:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()
