import sys

inf = 10000000000.0

def main():
    n = int(input().strip())

    arrA = list(map(int, input().strip().split()))

    cumSumA = [0] * (n + 1)
    for i in range(n):
        cumSumA[i + 1] = cumSumA[i] + arrA[i]

    ans = inf
    for i in range(1, n):
        if abs(cumSumA[n] - (cumSumA[i] * 2)) < ans:
            ans = abs(cumSumA[n] - cumSumA[i] * 2)

    print(int(ans))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
