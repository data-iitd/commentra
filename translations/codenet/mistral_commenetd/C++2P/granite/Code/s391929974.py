
while True:
    n = int(input())
    if n == 0:
        break
    sq = [i**2 % n for i in range(1, n)]
    com = list(set(sq))
    fr = [0] * (n//2 + 1)
    for i in range(len(com)):
        for j in range(len(com)):
            if i!= j:
                tmp = com[i] - com[j]
                if tmp < 0:
                    tmp += n
                if tmp > n//2:
                    tmp = n - tmp
                fr[tmp] += 1
    for i in range(1, n//2 + 1):
        print(fr[i])

