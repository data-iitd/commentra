#include<iostream>

using namespace std;

#define MAX_N 1e3

data = [0] * MAX_N

def main():
    m, nmi, nma = 0, 0, 0

    while True:
        m, nmi, nma = map(int, input().split())
        if nmi == 0:
            break

        for i in range(m):
            data[i] = int(input())

        ma = 0
        ans = 0

        for i in range(nmi - 1, nma - 1):
            if ma <= data[i] - data[i + 1]:
                ans = i + 1
                ma = data[i] - data[i + 1]

        print(ans)

if __name__ == "__main__":
    main()

