
N, K, R, S, P = map(int, input().split())
T = input()

dict = {"r": 0, "s": 0, "p": 0}
char = ""
s = [True] * N
r = [True] * N
p = [True] * N
for i in range(len(T)):
    char = T[i:i+1]
    if i >= K:
        if char == T[i-K:i+1-K]:
            if char == "s":
                if s[i%K]:
                    s[i%K] = False
                    continue
                else:
                    s[i%K] = True
            elif char == "r":
                if r[i%K]:
                    r[i%K] = False
                    continue
                else:
                    r[i%K] = True
            elif char == "p":
                if p[i%K]:
                    p[i%K] = False
                    continue
                else:
                    p[i%K] = True
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

