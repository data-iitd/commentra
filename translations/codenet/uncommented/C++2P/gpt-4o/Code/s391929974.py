def main():
    while True:
        n = int(input())
        if n == 0:
            break

        sq = [(i * i) % n for i in range(1, n)]
        com = []

        for i in range(1, n):
            if sq[i - 1] not in com:
                com.append(sq[i - 1])

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

if __name__ == "__main__":
    main()

# <END-OF-CODE>
