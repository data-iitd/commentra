

n, q = map(int, input().split())
s = input()
frag = [0] * (n + 1)
rui = [0] * (n + 1)
for i in range(2, n + 1):
    if s[i - 2:i] == 'AC':
        frag[i] += 1
    rui[i] = rui[i - 1] + frag[i]
for _ in range(q):
    l, r = map(int, input().split())
    print(rui[r] - rui[l])
