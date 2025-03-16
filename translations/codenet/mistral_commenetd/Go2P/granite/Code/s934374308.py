
N, K, R, S, P = map(int, input().split())
T = input()

dict = {"r": 0, "s": 0, "p": 0}

s = [True] * N
r = [True] * N
p = [True] * N

for i in range(len(T)):
    char = T[i:i+1]
    if i >= K and char == T[i-K:i+1-K]:
        if char == "s":
            s[i%K] = not s[i%K]
        elif char == "r":
            r[i%K] = not r[i%K]
        elif char == "p":
            p[i%K] = not p[i%K]
    else:
        if char == "s":
            s[i%K] = True
        elif char == "r":
            r[i%K] = True
        elif char == "p":
            p[i%K] = True

    if char == "s":
        dict["s"] += 1
    elif char == "r":
        dict["r"] += 1
    elif char == "p":
        dict["p"] += 1

res = P*dict["r"] + S*dict["p"] + R*dict["s"]
print(res)

