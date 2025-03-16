
import math

def main():
    n = int(input())

    arrA = list(map(int, input().split()))

    cumSumA = [0]
    for a in arrA:
        cumSumA.append(cumSumA[-1] + a)

    ans = 10000000000.0
    for i in range(1, n):
        if abs(cumSumA[n] - cumSumA[i]*2) < ans:
            ans = abs(cumSumA[n] - cumSumA[i]*2)

    print(int(ans))


