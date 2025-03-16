
import sys
def calculateMaxOfMin(arr, n):
    s = []
    left = [0] * n
    right = [0] * n
    ans = [0] * (n + 1)
    for i in range(n):
        left[i] = -1
        right[i] = n
    for i in range(n):
        while len(s) > 0 and arr[s[-1]] >= arr[i]:
            s.pop()
        if len(s) > 0:
            left[i] = s[-1]
        s.append(i)
    s.clear()
    for i in range(n - 1, -1, -1):
        while len(s) > 0 and arr[s[-1]] >= arr[i]:
            s.pop()
        if len(s) > 0:
            right[i] = s[-1]
        s.append(i)
    for i in range(n):
        len = right[i] - left[i] - 1
        ans[len] = max(ans[len], arr[i])
    for i in range(n - 1, 0, -1):
        ans[i] = max(ans[i], ans[i + 1])
    return ans

if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    result = calculateMaxOfMin(arr, n)
    print(*result)
