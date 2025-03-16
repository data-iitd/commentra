
n = int(input())
while n!= 0:
    sq = [i**2 % n for i in range(1, n)]
    com = []
    for i in range(1, n):
        if sq[i] not in com:
            com.append(sq[i])
    fr = [0] * (n // 2 + 1)
    for i in range(len(com)):
        for j in range(len(com)):
            if i!= j:
                tmp = com[i] - com[j]
                if tmp < 0:
                    tmp += n
                if tmp > (n - 1) // 2:
                    tmp = n - tmp
                fr[tmp] += 1
    for i in range(1, (n - 1) // 2 + 1):
        print(fr[i])
    n = int(input())

