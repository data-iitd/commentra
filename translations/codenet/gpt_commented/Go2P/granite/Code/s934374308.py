
N, K, R, S, P = map(int, input().split())
T = input()

dict = {"r": 0, "s": 0, "p": 0}
char = ""

s = [True] * N # For's'
r = s[:] # Copy the initial state to r
p = s[:] # Copy the initial state to p

for i in range(len(T)):
    char = T[i:i+1] # Get the current character

    if i >= K:
        if char == T[i-K:i+1-K]:
            if char == "s":
                if s[i%K]:
                    s[i%K] = False # Mark's' as used
                    continue
                else:
                    s[i%K] = True # Mark's' as available again
            elif char == "r":
                if r[i%K]:
                    r[i%K] = False # Mark 'r' as used
                    continue
                else:
                    r[i%K] = True # Mark 'r' as available again
            elif char == "p":
                if p[i%K]:
                    p[i%K] = False # Mark 'p' as used
                    continue
                else:
                    p[i%K] = True # Mark 'p' as available again
    else:
        if char == "s":
            s[i%K] = True # Mark's' as available
        elif char == "r":
            r[i%K] = True # Mark 'r' as available
        elif char == "p":
            p[i%K] = True # Mark 'p' as available

    if char == "s":
        dict["s"] += 1 # Increment count for's'
    elif char == "r":
        dict["r"] += 1 # Increment count for 'r'
    elif char == "p":
        dict["p"] += 1 # Increment count for 'p'

res = P*dict["r"] + S*dict["p"] + R*dict["s"]

print(res)

