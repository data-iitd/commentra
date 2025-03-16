def dfs(currpos, arr, target):
    if currpos == target:
        return True
    if currpos >= len(arr) + 1:
        return False
    teleport = dfs(currpos + arr[currpos - 1], arr, target)
    if teleport:
        return True
    return False

def main():
    n = int(input())
    goal = int(input())
    arr = [int(input()) for _ in range(n - 1)]
    is_found = dfs(1, arr, goal)
    if is_found:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
