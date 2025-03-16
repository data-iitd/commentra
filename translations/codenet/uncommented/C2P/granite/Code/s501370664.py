
import sys

def prime(num):
    flag = [0] * (num + 1)
    for i in range(2, int(num ** 0.5) + 1):
        if flag[i] == 0:
            for j in range(2, int((num - i) / i) + 1):
                flag[i * j] = 1
    return flag

def main():
    while True:
        n = int(input())
        if n == 0:
            break
        flag = prime(n)
        cnt = 0
        for i in range(2, n // 2 + 1):
            if flag[i] == 0 and flag[n - i] == 0:
                cnt += 1
        print(cnt)

if __name__ == "__main__":
    main()

