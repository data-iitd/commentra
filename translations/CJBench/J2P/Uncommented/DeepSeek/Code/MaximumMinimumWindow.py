def calculate_max_of_min(arr, n):
    s = []
    left = [-1] * n
    right = [n] * n
    ans = [0] * (n + 1)
    
    for i in range(n):
        while s and arr[s[-1]] >= arr[i]:
            s.pop()
        if s:
            left[i] = s[-1]
        s.append(i)
    
    s.clear()
    
    for i in range(n - 1, -1, -1):
        while s and arr[s[-1]] >= arr[i]:
            s.pop()
        if s:
            right[i] = s[-1]
        s.append(i)
    
    for i in range(n):
        length = right[i] - left[i] - 1
        ans[length] = max(ans[length], arr[i])
    
    for i in range(n - 1, 0, -1):
        ans[i] = max(ans[i], ans[i + 1])
    
    return ans[1:]

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    result = calculate_max_of_min(arr, n)
    print(" ".join(map(str, result)))

main()
