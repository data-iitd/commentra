def calculate_max_of_min(arr, n):
    stack = []
    left = [-1] * n
    right = [n] * n
    ans = [0] * (n + 1)

    for i in range(n):
        while stack and arr[stack[-1]] >= arr[i]:
            stack.pop()
        if stack:
            left[i] = stack[-1]
        stack.append(i)

    stack.clear()
    for i in range(n - 1, -1, -1):
        while stack and arr[stack[-1]] >= arr[i]:
            stack.pop()
        if stack:
            right[i] = stack[-1]
        stack.append(i)

    for i in range(n):
        length = right[i] - left[i] - 1
        ans[length] = max(ans[length], arr[i])

    for i in range(n - 1, 0, -1):
        ans[i] = max(ans[i], ans[i + 1])

    return ans

if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    result = calculate_max_of_min(arr, n)
    print(" ".join(map(str, result[1:])))
    
# <END-OF-CODE>
