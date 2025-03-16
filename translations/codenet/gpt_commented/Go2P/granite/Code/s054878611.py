
def solution(n, a):
    memo = [0] * (100002)
    for num in a:
        memo[num] += 1
        memo[num + 1] += 1
        memo[num + 2] += 1
    out = 0
    for num in memo:
        if num > 0:
            out = max(out, num)
    return out

def max(x, y):
    if x > y:
        return x
    return y

n = int(input())
a = list(map(int, input().split()))
print(solution(n, a))
