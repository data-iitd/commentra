
def Abs(x):
    if x < 0:
        return -x
    return x

def min(a, b):
    if a > b:
        return b
    return a

N, K = map(int, input().split())

hm = {}
while True:
    if N not in hm:
        hm[N] = True
        N = Abs(N - K)
    else:
        break

mini = 999999999
for k in hm:
    mini = min(mini, k)

print(mini)

