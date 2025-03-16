

import sys

def main():
    N, K = map(int, sys.stdin.readline().split())
    S = sys.stdin.readline().strip()

    c1 = list(S)
    c3 = list(S)

    flag1 = False
    count1 = 0

    for i in range(N):
        if flag1 and c1[i] == 'R':
            flag1 = False
            count1 += 1
        if count1 == K:
            break
        if c1[i] == 'L':
            flag1 = True

    flag3 = False
    count3 = 0

    for i in range(N):
        if flag3 and c3[i] == 'L':
            flag3 = False
            count3 += 1
        if count3 == K:
            break
        if c3[i] == 'R':
            flag3 = True

    S1 = ''.join(c1)
    S3 = ''.join(c3)

    count2 = 1
    sum1 = 0
    bef1 = S1[0]

    for i in range(1, N):
        if S1[i] == bef1:
            count2 += 1
        else:
            sum1 += count2 - 1
            count2 = 1
            bef1 = S1[i]

    sum1 += count2 - 1

    count4 = 1
    sum3 = 0
    bef3 = S3[0]

    for i in range(1, N):
        if S3[i] == bef3:
            count4 += 1
        else:
            sum3 += count4 - 1
            count4 = 1
            bef3 = S3[i]

    sum3 += count4 - 1

    print(max(sum1, sum3))

if __name__ == '__main__':
    main()

