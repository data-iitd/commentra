import sys
from collections import defaultdict

def dfs(left, i, res):
    global ans
    if left == 0:
        ans += res
        return
    for j in range(i, len(a)):
        dfs(left - 1, j + 1, res * a[j])

if __name__ == "__main__":
    input = sys.stdin.read
    data = input().splitlines()
    
    n = int(data[0])
    dic = defaultdict(int)

    for i in range(1, n + 1):
        c = data[i][0]
        if c in 'MARCH':
            dic[c] += 1

    a = list(dic.values())
    ans = 0

    dfs(3, 0, 1)
    print(ans)

# <END-OF-CODE>
