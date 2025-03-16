
import sys

def main():
    n = int(input())
    ch = []
    s1 = 0
    s2 = 0
    i = 0
    j = 0
    flag = 0
    dif = 0
    for i in range(n):
        x = int(input())
        y = int(input())
        temp1 = s1 + x
        temp2 = s2 + y
        if (abs(temp1 - s2) <= 500):
            s1 += x
            ch.append('A')
            continue
        if (abs(temp2 - s1) <= 500):
            s2 += y
            ch.append('G')
            continue
        flag = 1
        break
    if (flag == 1):
        print(-1)
    else:
        ans = ''.join(ch)
        print(ans)

if __name__ == "__main__":
    main()

