
import sys

N, K, R, S, P = map(int, sys.stdin.readline().split())
T = sys.stdin.readline().strip()

dict = {"r": 0, "s": 0, "p": 0}
char = ""
s = [True] * N
for i in range(N):
    s[i] = True
r = [True] * N
p = [True] * N
copy(r, s)
copy(p, s)
for i in range(len(T)):
    char = T[i]
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
        dict["s"] = dict["s"] + 1
    elif char == "r":
        dict["r"] = dict["r"] + 1
    elif char == "p":
        dict["p"] = dict["p"] + 1

res = P*dict["r"] + S*dict["p"] + R*dict["s"]
print(res)

