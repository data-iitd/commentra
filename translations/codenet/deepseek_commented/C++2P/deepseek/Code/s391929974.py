import sys

while True:
    n = int(input().strip())
    if n == 0:
        break

    sq = [0] * 10000
    fr = [0] * 5000
    com = []

    for i in range(1, n):
        sq[i] = (i * i) % n

    com = []

    for i in range(1, n):
        unique = True
        for j in com:
            if j == sq[i]:
                unique = False
                break
        if unique:
            com.append(sq[i])

    fr = [0] * ((n - 1) // 2 + 1)

    for i in range(len(com)):
        for j in range(len(com)):
            if i != j:
                tmp = com[i] - com[j]
                if tmp < 0:
                    tmp += n
                if tmp > (n - 1) // 2:
                    tmp = n - tmp
                fr[tmp] += 1

    for i in range(1, (n - 1) // 2 + 1):
        print(fr[i])

print("<END-OF-CODE>")