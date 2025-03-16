def main():
    N, K, R, S, P = map(int, input().split())
    T = input().strip()

    dict_count = {"r": 0, "s": 0, "p": 0}
    char = ""
    s = [True] * N
    r = [True] * N
    p = [True] * N

    for i in range(N):
        char = T[i]
        if i >= K:
            if char == T[i - K]:
                if char == "s":
                    if s[i % K]:
                        s[i % K] = False
                        continue
                    else:
                        s[i % K] = True
                elif char == "r":
                    if r[i % K]:
                        r[i % K] = False
                        continue
                    else:
                        r[i % K] = True
                elif char == "p":
                    if p[i % K]:
                        p[i % K] = False
                        continue
                    else:
                        p[i % K] = True
            else:
                if char == "s":
                    s[i % K] = True
                elif char == "r":
                    r[i % K] = True
                elif char == "p":
                    p[i % K] = True

        dict_count[char] += 1

    res = P * dict_count["r"] + S * dict_count["p"] + R * dict_count["s"]
    print(res)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
