def prime(num):
    global flag
    flag = [0] * (num + 1)

    for i in range(2, int(num**0.5) + 1):
        if flag[i] == 0:
            for j in range(2, num // i + 1):
                flag[i * j] = 1

if __name__ == "__main__":
    prime(50000)

    while True:
        n = int(input())
        if n == 0:
            break
        i = 2
        cnt = 0
        while i * 2 <= n:
            if flag[i] == 0 and flag[n - i] == 0:
                cnt += 1
            i += 1
        print(cnt)

# <END-OF-CODE>
