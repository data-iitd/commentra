
# <START-OF-CODE>

import sys

def main():
    N = int(sys.stdin.readline())
    count = 0
    temp = N
    ans = 0
    while temp > 0:
        temp /= 10
        count += 1
    for i in range(1, count + 1):
        if i == count:
            if i % 2 == 1:
                ans += (N - pow(10, i - 1) + 1)
        else:
            if i == 1:
                ans += 9
            else:
                if i % 2 == 1:
                    ans += (pow(10, i) - pow(10, i - 1))
    print(ans)

if __name__ == '__main__':
    main()

# 