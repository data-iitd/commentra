from collections import deque

def main():
    n = int(input())
    a = list(map(int, input().split()))
    
    leftl = [0] * n
    rightl = [0] * n
    que = deque()
    
    # Calculate rightl
    index = 0
    while index < n:
        while que and a[que[-1]] > a[index]:
            ind = que.pop()
            rightl[ind] = index - ind - 1
        que.append(index)
        index += 1
    while que:
        ind = que.pop()
        rightl[ind] = n - ind - 1
    
    # Calculate leftl
    index = n - 1
    que = deque()
    while index >= 0:
        while que and a[que[-1]] > a[index]:
            ind = que.pop()
            leftl[ind] = ind - index - 1
        que.append(index)
        index -= 1
    while que:
        ind = que.pop()
        leftl[ind] = ind - index - 1
    
    ans = 0
    for i in range(n):
        ans += a[i] * (leftl[i] + 1) * (rightl[i] + 1)
    
    print(ans)

if __name__ == "__main__":
    main()
